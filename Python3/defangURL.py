import os

is_running = True
z = 0
os.system('cls')

# Program to return 'employer' of given URLs
# Example: https://www.stackoverflow.com/questions/

while is_running:
    input_URL = str(input('Enter URL: '))

    # Step 1: Remove protocol and "www." prefix if present
    if input_URL.startswith("https://www."):
        input_URL = input_URL.replace("https://www.", "", 1)
    elif input_URL.startswith("http://www."):
        input_URL = input_URL.replace("http://www.", "", 1)
    elif input_URL.startswith("www."):
        input_URL = input_URL.replace("www.", "", 1)
    elif input_URL.startswith("https://"):
        input_URL = input_URL.replace("https://", "", 1)
    elif input_URL.startswith("http://"):
        input_URL = input_URL.replace("http://", "", 1)

    # Step 2: Find the next "." in the modified string and extract everything before it
    y = 0
    for x in input_URL:
        y += 1
        if x == ".":
            input_URL = input_URL[:y-1]
            print(f"Deconcatenated: {input_URL}")
            z += 1  # Increment URL count
            with open('URLEmployer.txt', 'a') as f:  # Append mode
                print(f'#{z}: {input_URL}', file=f)
            break  # Stop after extracting the employer part