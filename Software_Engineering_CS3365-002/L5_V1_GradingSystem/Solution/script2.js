// Function to calculate grade using if-else statements
function gradeWithIfElse(score) {
    if (score >= 90 && score <= 100) {
        return "Grade A";
    } else if (score >= 80 && score < 90) {
        return "Grade B";
    } else if (score >= 70 && score < 80) {
        return "Grade C";
    } else if (score >= 60 && score < 70) {
        return "Grade D";
    } else if (score < 60 && score >= 0) {
        return "Grade F";
    } else {
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
    const grade = gradeWithIfElse(score);
    document.getElementById("result").innerText = `Your grade is: ${grade}`;
}
