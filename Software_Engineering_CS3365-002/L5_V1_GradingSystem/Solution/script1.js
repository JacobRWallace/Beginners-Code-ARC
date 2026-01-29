// Function to calculate grade using a switch statement
function gradeWithSwitch(score) {
    switch (true) {
        case score >= 90:
            return "Grade A";
        case score >= 80:
            return "Grade B";
        case score >= 70:
            return "Grade C";
        case score >= 60:
            return "Grade D";
        case score < 60 && score >= 0:
            return "Grade F";
        default:
            return "Invalid score. Please enter a score between 0 and 100.";
    }
}

// Ask the user for input
const inputScore = prompt("Enter your score (0-100):");

// Convert the input to a number
const score = Number(inputScore);

// Validate the input and display the result
if (isNaN(score)) {
    document.getElementById("result").innerText = "Invalid input. Please enter a numeric value.";
} else {
    const grade = gradeWithSwitch(score);
    document.getElementById("result").innerText = `Your grade is: ${grade}`;
}
