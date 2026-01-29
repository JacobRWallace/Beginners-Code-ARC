
// Calculator Functionality

let currentInput = "0";
let enteredInput = "";
let operator = "";

let display = document.getElementById("box");

function updateDisplay(value) {
    display = document.getElementById("box");
    display.textContent = value;
    //historyDisplay.textContent = previousInput + (operator || "");
}

function button_number(button) {
    if (button === '+') {
        currentInput = parseFloat(enteredInput) + parseFloat(currentInput);
    } else if (button === '-') {
        
    } else if (button === '*') {
        
    } else if (button === '/') {
        
    } else if (button === '=') {
        
    } else if (button === '.') {
        
    } else if (button === '0') {
        
    } else if (button === 1) {
        console.log("1 pressed!");
        currentInput += "1";
        updateDisplay(currentInput);
    } else if (button === 2) {
        console.log("2 pressed!");
        currentInput += "2";
        updateDisplay(currentInput);
    } else if (button === 3) {
        console.log("3 pressed!");
        currentInput += "3";
        updateDisplay(currentInput);
    } else if (button === 4) {
        console.log("4 pressed!");
        currentInput += "4";
        updateDisplay(currentInput);
    } else if (button === 5) {
        console.log("5 pressed!");
        currentInput += "5";
        updateDisplay(currentInput);
    } else if (button === 6) {
        console.log("6 pressed!");
        currentInput += "6";
        updateDisplay(currentInput);
    } else if (button === 7) {
        console.log("7 pressed!");
        currentInput += "7";
        updateDisplay(currentInput);
    } else if (button === 8) {
        console.log("8 pressed!");
        currentInput += "8";
        updateDisplay(currentInput);
    } else if (button === 9) {
        console.log("9 pressed!");
        currentInput += "9";
        updateDisplay(currentInput);
    }
}

function calculate_percentage() {
    
}

function clear_entry() {

}

function button_clear() {
    currentInput = "0";
    updateDisplay(currentInput)
}

function backspace_remove() {

}

function division_one() {

}

function power_of() {

}

function square_root() {

}

function plus_minus() {

}

function showSelectedOperator() {

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