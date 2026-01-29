// Grade Calculator Template

// Function to calculate the grade (you can choose switch or if-else logic)
function calculateGrade(score) {
    // TODO: Add your grade calculation logic here
    // Example: Use switch or if-else to assign grades based on the score
}

// Prompt the user to input their score
const inputScore = prompt("Enter your score (0-100):");

// Convert the input to a number
const score = Number(inputScore);

// Validate the input
if (isNaN(score) || score < 0 || score > 100) {
    console.log("Invalid input. Please enter a numeric value between 0 and 100.");
} else {
    // Call the calculateGrade function and display the result
    const grade = calculateGrade(score);
    console.log(`Your grade is: ${grade}`);
    // TODO: Optionally display the grade on the webpage
}
