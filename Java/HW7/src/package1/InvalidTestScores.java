package package1;

/**
 * Custom exception for invalid test scores.
 */
public class InvalidTestScores extends Exception {
    public InvalidTestScores(String message) {
        super(message);
    }
}