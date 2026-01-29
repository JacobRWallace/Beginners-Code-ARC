
// Calculator Functionality

let currentInput = "0";
let enteredInput = "";
let operator = ""; 
    
let display = document.getElementById("box");
let history = document.getElementById("last_operation_history");

function updateDisplay(value) {
    console.log("Display Updated!");
    display = document.getElementById("box");
    display.textContent = value;
}
 
function updateHistory(value) {
    console.log("History Updated!");
    historyDisplay = document.getElementById("last_operation_history");
    historyDisplay.textContent = value;
}
 
function button_number(button) {
    if (button === '+') {
        operator = "+"; 
        enteredInput = currentInput;
        updateHistory(enteredInput + " " + operator);
        currentInput = "0"; 
    } else if (button === '-') {
        operator = "-"; 
        enteredInput = currentInput;
        updateHistory(enteredInput + " " + operator);
        currentInput = "0"; 
    } else if (button === '*') {
        operator = "*"; 
        enteredInput = currentInput;
        updateHistory(enteredInput + " " + operator);
        currentInput = "0"; 
    } else if (button === '/') {
        operator = "/"; 
        enteredInput = currentInput;
        updateHistory(enteredInput + " " + operator);
        currentInput = "0"; 

    } else if (button === "=") { //output computation and update
        if (operator && enteredInput) {
            let output; 
             
            if (operator === "+") {
                output = parseFloat(enteredInput) + parseFloat(currentInput);} 

            else if (operator === "-") {
                output = parseFloat(enteredInput) - parseFloat(currentInput);}
 
            else if (operator === "*") {
                output = parseFloat(enteredInput) * parseFloat(currentInput);} 
                
            else if (operator === "/") { 
                output = currentInput === "0" ? "Error" : parseFloat(enteredInput) / parseFloat(currentInput); }  
              
            updateHistory(enteredInput + " " + operator + " " + currentInput + " =");
            currentInput = output.toString();
            operator = ""; 
            enteredInput = ""; 
        }
         
    } else if (button === '.') {
        if (!currentInput.includes(".")) { 
            currentInput += ".";
        }  
    }

    //all numbers 
    else {
        if (currentInput === "0" || currentInput === "Error") {
            console.log("number!")
            currentInput = button.toString();}
        else {
            currentInput += button.toString();}  
    }
 
    updateDisplay(currentInput);
}

function calculate_percentage() { 
    updateHistory(currentInput + "%");
    currentInput = (parseFloat(currentInput) / 100).toString(); 
    updateDisplay(currentInput); 
}

function clear_entry() {
    currentInput = "0";
    updateDisplay(currentInput);
}

function button_clear() { 
    currentInput = "0"; 
    enteredInput = "";
    operator = ""; 
    updateHistory(""); // Clear history
    updateDisplay(currentInput);
}

function backspace_remove() {
    currentInput = currentInput.length > 1 ? currentInput.slice(0, -1) : "0";
    updateDisplay(currentInput);
}

function division_one() { 
    if (currentInput !== "0") {
        updateHistory("1 / " + currentInput); 
        currentInput = (1 / parseFloat(currentInput)).toString();
    } else {
        currentInput = "Error!"; 
    }
    updateDisplay(currentInput);
}

function power_of() {
    updateHistory(currentInput + "²");
    currentInput = Math.pow(parseFloat(currentInput), 2).toString();
    updateDisplay(currentInput);
}

function square_root() {
    if (parseFloat(currentInput) >= 0) {
        updateHistory("√" + currentInput);
        currentInput = Math.sqrt(parseFloat(currentInput)).toString();
    } else {
        currentInput = "Error!";
    }
    updateDisplay(currentInput); 
}

function plus_minus() {
    updateHistory("±" + currentInput);
    currentInput = (parseFloat(currentInput) * -1).toString();
    updateDisplay(currentInput); 
}

//globalize functions 
window.button_number = button_number;
window.button_clear = button_clear;
window.clear_entry = clear_entry;
window.backspace_remove = backspace_remove;
window.calculate_percentage = calculate_percentage;
window.square_root = square_root;
window.power_of = power_of; 
window.division_one = division_one;
window.plus_minus = plus_minus; 
 
button_clear(); //just an initial reset for calculator on launch 