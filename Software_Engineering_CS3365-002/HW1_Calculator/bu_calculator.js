
// Calculator Functionality

let currentInput = "0";
let enteredInput = "";
let operator = "";

const display = document.getElementById("box");

function updateDisplay() {
    display.textContent = currentInput;
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
        currentInput = "1";
        updateDisplay();
    } else if (button === '2') {
        
    } else if (button === '3') {
        
    } else if (button === '4') {
        
    } else if (button === '5') {
        
    } else if (button === '6') {
        
    } else if (button === '7') {
        
    } else if (button === '8') {
        
    } else if (button === '9') {
        
    }
}

function calculate_percentage() {
    
}

function clear_entry() {

}

function button_clear() {

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