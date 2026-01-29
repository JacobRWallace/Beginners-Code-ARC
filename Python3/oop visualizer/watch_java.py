import os
import time
import re
from typing import List, Dict

JAVA_FILE = "target.java"
POLL_INTERVAL = 0.5  # seconds


def read_file(path: str) -> str:
    try:
        with open(path, "r", encoding="utf-8") as f:
            return f.read()
    except FileNotFoundError:
        return ""


def parse_java_structure(source: str) -> List[Dict]:
    """
    VERY SIMPLE parser to find:
      - class names
      - fields (rough guess)
      - methods

    This is not a real Java parser, just enough to visualize OOP ideas.
    """
    classes = []

    # Naive regex: matches "class ClassName { ... }"
    # with minimal nesting awareness.
    class_pattern = re.compile(
        r"class\s+(\w+)\s*(?:extends\s+\w+)?\s*(?:implements\s+[^{]+)?\{",
        re.MULTILINE
    )

    # Find all class declarations with their start index
    matches = list(class_pattern.finditer(source))

    for i, m in enumerate(matches):
        class_name = m.group(1)
        start = m.end()
        end = matches[i + 1].start() if i + 1 < len(matches) else len(source)
        class_body = source[start:end]

        # Fields: very naive
        # Roughly matches: [visibility] [static] type name [= ...] ;
        field_pattern = re.compile(
            r"(public|private|protected)?\s*(static)?\s*([\w<>?\[\]]+)\s+(\w+)\s*(=.*?)?;",
            re.MULTILINE
        )

        # Methods: match "[vis] [static] returnType name(...){"
        method_pattern = re.compile(
            r"(public|private|protected)?\s*(static)?\s*([\w<>?\[\]]+)\s+(\w+)\s*\(([^)]*)\)\s*\{",
            re.MULTILINE
        )

        fields = []
        methods = []

        for fmatch in field_pattern.finditer(class_body):
            f_vis, f_static, f_type, f_name, _ = fmatch.groups()
            fields.append({
                "visibility": f_vis or "",
                "static": bool(f_static),
                "type": f_type,
                "name": f_name,
            })

        for mmatch in method_pattern.finditer(class_body):
            m_vis, m_static, m_ret, m_name, m_params = mmatch.groups()
            params = [p.strip() for p in m_params.split(",") if p.strip()]
            methods.append({
                "visibility": m_vis or "",
                "static": bool(m_static),
                "return": m_ret,
                "name": m_name,
                "params": params,
            })

        classes.append({
            "name": class_name,
            "fields": fields,
            "methods": methods,
        })

    return classes


def print_structure(classes: List[Dict]):
    os.system("cls" if os.name == "nt" else "clear")
    print(f"=== Parsed structure of {JAVA_FILE} ===\n")

    if not classes:
        print("No classes found yet. Type something like:\n")
        print("  public class Example {\n      private int x;\n      public void foo() {}\n  }\n")
        return

    for cls in classes:
        print(f"Class: {cls['name']}")
        print("  Fields:")
        if not cls["fields"]:
            print("    (none)")
        else:
            for f in cls["fields"]:
                vis = f["visibility"] or "package-private"
                static = " static" if f["static"] else ""
                print(f"    {vis}{static} {f['type']} {f['name']}")

        print("  Methods:")
        if not cls["methods"]:
            print("    (none)")
        else:
            for m in cls["methods"]:
                vis = m["visibility"] or "package-private"
                static = " static" if m["static"] else ""
                params = ", ".join(m["params"])
                print(f"    {vis}{static} {m['return']} {m['name']}({params})")
        print()


def watch_file():
    print(f"Watching {JAVA_FILE} for changes... (Ctrl+C to stop)")
    last_mtime = None
    last_content = ""

    while True:
        if os.path.exists(JAVA_FILE):
            mtime = os.path.getmtime(JAVA_FILE)
            if last_mtime is None or mtime != last_mtime:
                last_mtime = mtime
                content = read_file(JAVA_FILE)

                # Only re-parse if content actually changed
                if content != last_content:
                    last_content = content
                    classes = parse_java_structure(content)
                    print_structure(classes)
        else:
            os.system("cls" if os.name == "nt" else "clear")
            print(f"{JAVA_FILE} not found in {os.getcwd()}")
            print("Create it and start typing Java classes...")
        time.sleep(POLL_INTERVAL)


if __name__ == "__main__":
    try:
        watch_file()
    except KeyboardInterrupt:
        print("\nStopped.")
