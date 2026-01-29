package ClassWork103024;

public class TTU_Student extends College implements TTU_st, TTU_st1, TTU_st2 {

    // Private fields for the student's details
    private String name; // Student's name
    private double score; // Student's score
    private boolean passfail; // Pass/fail status based on score
    private String college; // College of enrollment
    private int ID; // Student's ID number

    /**
     * Sets the student's name.
     * @param name The name of the student
     */
    public void setName(String name) {
        this.name = name;
    }

    /**
     * Retrieves the student's name.
     * @return The student's name
     */
    public String getName() {
        return name;
    }

    /**
     * Sets the student's score.
     * @param score The score of the student
     */
    public void setScore(double score) {
        this.score = score;
    }

    /**
     * Retrieves the student's score.
     * @return The student's score
     */
    public double getScore() {
        return score;
    }

    /**
     * Sets the student's pass/fail status.
     * @param pf The pass/fail status
     */
    public void setPassFail(boolean pf) {
        passfail = pf;
    }

    /**
     * Retrieves the student's pass/fail status.
     * @return The pass/fail status
     */
    public boolean getPassFail() {
        return passfail;
    }

    /**
     * Sets the student's college of enrollment.
     * @param college The name of the college
     */
    public void setCollege(String college) {
        this.college = college;
    }

    /**
     * Retrieves the student's college of enrollment.
     * @return The name of the college
     */
    public String getCollege() {
        return college;
    }

    /**
     * Sets the student's ID.
     * @param ID The student ID number
     */
    public void setID(int ID) {
        this.ID = ID;
    }

    /**
     * Retrieves the student's ID.
     * @return The student ID number
     */
    public int getID() {
        return ID;
    }

    /**
     * Displays the student's information.
     */
    public void display() {
        System.out.println("ID: " + ID);
        System.out.println("Name: " + name);
        System.out.println("Score: " + score);
        System.out.println("Pass/Fail: " + passfail);
        System.out.println("College: " + college);
    }
}
