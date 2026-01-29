// Wait for the page to fully load before running the script
document.addEventListener("DOMContentLoaded", function () {
    // Get references to the calculator's display and history elements
    let display = document.getElementById("box");
    let history = document.getElementById("last_operation_history");

    // Store the current input and result
    let currentInput = "0";  // The number currently being entered
    let lastResult = "";  // The result of the last calculation

    // Function to update the calculator's display
    function updateDisplay(value) {
        display.textContent = value;
    }

    // Function to handle number and operator button clicks
    function button_number(value) {
        if (value === "=") {
            try {
                // Show the calculation history
                history.textContent = currentInput;

                // Evaluate the math expression and update the display
                currentInput = eval(currentInput).toString();
                lastResult = currentInput;
            } catch (error) {
                currentInput = "Error"; // Handle invalid expressions
            }
        } else {
            // If starting fresh or after an error, replace the input
            if (currentInput === "0" || currentInput === "Error") {
                currentInput = value.toString();
            } else {
                currentInput += value.toString(); // Append new input
            }
        }

        updateDisplay(currentInput); // Show the updated input
    }

    // Function to clear everything (C button)
    function button_clear() {
        currentInput = "0";  // Reset input
        history.textContent = ""; // Clear history
        updateDisplay(currentInput);
    }

    // Function to clear only the last entry (CE button)
    function clear_entry() {
        currentInput = "0"; // Reset only the current input
        updateDisplay(currentInput);
    }

    // Function to remove the last digit (Backspace button)
    function backspace_remove() {
        if (currentInput.length > 1) {
            currentInput = currentInput.slice(0, -1); // Remove last character
        } else {
            currentInput = "0"; // If empty, reset to zero
        }
        updateDisplay(currentInput);
    }

    // Function to calculate percentage (% button)
    function calculate_percentage() {
        currentInput = (parseFloat(currentInput) / 100).toString();
        updateDisplay(currentInput);
    }

    // Function to calculate the square root (√x button)
    function square_root() {
        currentInput = Math.sqrt(parseFloat(currentInput)).toString();
        updateDisplay(currentInput);
    }

    // Function to square the number (x² button)
    function power_of() {
        currentInput = Math.pow(parseFloat(currentInput), 2).toString();
        updateDisplay(currentInput);
    }

    // Function to calculate 1 divided by the number (1/x button)
    function division_one() {
        currentInput = (1 / parseFloat(currentInput)).toString();
        updateDisplay(currentInput);
    }

    // Function to change the sign of the number (± button)
    function plus_minus() {
        currentInput = (parseFloat(currentInput) * -1).toString();
        updateDisplay(currentInput);
    }

    // Make functions available globally so they work with button clicks in HTML
    window.button_number = button_number;
    window.button_clear = button_clear;
    window.clear_entry = clear_entry;
    window.backspace_remove = backspace_remove;
    window.calculate_percentage = calculate_percentage;
    window.square_root = square_root;
    window.power_of = power_of;
    window.division_one = division_one;
    window.plus_minus = plus_minus;

    // Initialize the calculator display
    button_clear();
});