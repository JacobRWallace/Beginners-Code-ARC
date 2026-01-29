// Grade System Configuration
const gradeSystem = {
  A: { min: 90, message: "Excellent! Keep it up! 🎉", color: "#28a745" },
  B: { min: 80, message: "Great job! Keep improving! 😊", color: "#4CAF50" },
  C: { min: 70, message: "Good effort, but there's room for improvement! 💪", color: "#FFC107" },
  D: { min: 60, message: "You passed, but work harder! 📚", color: "#FF9800" },
  F: { min: 0, message: "Failed. Don't give up, try again! 🚀", color: "#dc3545" }
};

// Function to determine grade based on score
function getGrade(score) {
  for (let grade in gradeSystem) {
    if (score >= gradeSystem[grade].min) {
      return grade;
    }
  }
  return 'F'; // Default to 'F' if no grade matches
}

// Grab elements
const nameInput = document.getElementById('nameInput');
const checkScoreBtn = document.getElementById('checkScoreBtn');
const scoreResult = document.getElementById('scoreResult');

// Array of student objects
const studentsData = [
  { name: "Alice", score: 95 },
  { name: "Bob", score: 78 },
  { name: "Charlie", score: 88 },
  { name: "Maaz", score: 95 },
  // Add more if you like
];

// When the user clicks the "Check Score" button
checkScoreBtn.addEventListener('click', () => {
  const enteredName = nameInput.value.trim().toLowerCase();

  if (enteredName === "") {
    alert("Please enter a student's name.");
    return;
  }

  // Find the student in the array by matching the name (case-insensitive)
  const student = studentsData.find(
    stu => stu.name.toLowerCase() === enteredName
  );

  if (student) {
    const grade = getGrade(student.score);
    const { message, color } = gradeSystem[grade];

    // Display output text + name
    scoreResult.innerText = `${student.name}'s score is ${student.score}.\nGrade: ${grade}.\n${message}`;
    
    // Apply color based on grade
    scoreResult.style.color = color;
  } else {
    scoreResult.innerText = `No record found for "${nameInput.value}".`;
    scoreResult.style.color = "#dc3545"; // Red color for not found
  }

  // Clear the input if you want
  nameInput.value = '';
});
