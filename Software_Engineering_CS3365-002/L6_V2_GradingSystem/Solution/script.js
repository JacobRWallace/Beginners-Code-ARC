// Grade System Configuration
const gradeSystem = {
  E:{ min: 95, message: "Excellent! Keep it up! 🎉", color: "#4b0082" },
  A: { min: 90, message: "Excellent! Keep it up! 🎉", color: "#6a0dad" },
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

// Example array of student objects with subject
const studentsData = [
  { name: "Alice", score: 95, subject: "Mathematics" },
  { name: "Maaz Amjad", score: 78, subject: "Physics" },
  { name: "Charlie", score: 88, subject: "Chemistry" },
  { name: "Maaz", score: 97, subject: "CS" },
  { name: "Bob", score: 92, subject: "Biology" },
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

    // Determine if high score
    const isHighScore = student.score > 95;
    let highScoreIcon = '';

    if (isHighScore) {
      highScoreIcon = ' 👍'; // Unicode thumb up icon
      scoreResult.classList.add('high-score'); // Applies special styling
    } else {
      scoreResult.classList.remove('high-score'); // Removes special styling if not a high score
    }

    // Display output text + name + subject
    scoreResult.innerText = `${student.name}'s score in ${student.subject} is ${student.score}.\nGrade: ${grade}.\n${message}${highScoreIcon}`;
    
    // Apply color based on grade
    scoreResult.style.color = color;
  } else {
    scoreResult.innerText = `No record found for "${nameInput.value}".`;
    scoreResult.style.color = "#dc3545"; // Red color for not found
    scoreResult.classList.remove('high-score'); // Remove high-score class if any
  }

  // Clear the input if you want
  nameInput.value = '';
});
