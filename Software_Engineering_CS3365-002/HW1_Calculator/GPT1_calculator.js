// calculator.js

let currentInput = "0";
let previousInput = "";
let operator = null;

const display = document.getElementById("box");
const historyDisplay = document.getElementById("last_operation_history");

function updateDisplay() {
    display.textContent = currentInput;
    historyDisplay.textContent = previousInput + (operator || "");
}

function button_number(value) {
    if (value === "=") {
        if (operator && previousInput !== "") {
            currentInput = calculate_result();
            operator = null;
            previousInput = "";
        }
    } else if (isNaN(value) && value !== ".") {
        if (currentInput !== "") {
            operator = value;
            previousInput = currentInput;
            currentInput = "";
        }
    } else {
        if (currentInput === "0" && value !== ".") {
            currentInput = value.toString();
        } else {
            currentInput += value.toString();
        }
    }
    updateDisplay();
}

function calculate_result() {
    let result;
    const num1 = parseFloat(previousInput);
    const num2 = parseFloat(currentInput);
    switch (operator) {
        case "+": result = num1 + num2; break;
        case "-": result = num1 - num2; break;
        case "*": result = num1 * num2; break;
        case "/": result = num2 !== 0 ? num1 / num2 : "Error"; break;
        default: return currentInput;
    }
    return result.toString();
}

function calculate_percentage() {
    currentInput = (parseFloat(currentInput) / 100).toString();
    updateDisplay();
}

function clear_entry() {
    currentInput = "0";
    updateDisplay();
}

function button_clear() {
    currentInput = "0";
    previousInput = "";
    operator = null;
    updateDisplay();
}

function backspace_remove() {
    currentInput = currentInput.slice(0, -1) || "0";
    updateDisplay();
}

function division_one() {
    if (currentInput !== "0") {
        currentInput = (1 / parseFloat(currentInput)).toString();
    } else {
        currentInput = "Error";
    }
    updateDisplay();
}

function power_of() {
    currentInput = (Math.pow(parseFloat(currentInput), 2)).toString();
    updateDisplay();
}

function square_root() {
    currentInput = (Math.sqrt(parseFloat(currentInput))).toString();
    updateDisplay();
}

function plus_minus() {
    currentInput = (parseFloat(currentInput) * -1).toString();
    updateDisplay();
}

// Initialize Display
updateDisplay();
