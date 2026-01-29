"use client"
function Form({ todos, setTodos }) {
  const handleSubmit = (event) => {
    event.preventDefault();

    const value = event.target.todo.value;
    const newTodo = {
      title: value,
      id: self.crypto.randomUUID(),
      is_completed: false,
    };

    // Update todo state
    setTodos((prevTodos) => [...prevTodos, newTodo]);

    // Store updated todo list in local storage
    const updatedTodoList = JSON.stringify([...todos, newTodo]);
    localStorage.setItem("todos", updatedTodoList);

    event.target.reset();
  };

  return (
    <form className="form" onSubmit={handleSubmit}>
      <label htmlFor="todo">
        <input
          type="text"
          name="todo"
          id="todo"
          placeholder="Write your next task"
        />
      </label>

      <button>
        <span className="visually-hidden">Submit</span>
        <svg>
          <path
            d=""/>
        </svg>
      </button>
    </form>
  );
}

export default Form;
