package package1;

/**
 * calculates the average of test scores
 * @author Jacob Wallace
 * @date 11/15/24
 */
public class TestScores {
    private int[] scores;

    /**
     * constructor that accepts array of test scores
     * @param scores array of test scores
     * @throws InvalidTestScore if scores are out of range
     */
    public TestScores(int[] scores) throws InvalidTestScores {
        for (int score : scores) {
            if (score < 0 || score > 100) {
                throw new InvalidTestScores("Scores must be between 0 and 100.");
            }
        }
        this.scores = scores;
    }

    /**
     * calculate the average of test scores
     * @return average score
     */
    public double getAverage() {
        int sum = 0;
        for (int score : scores) {
            sum += score;
        }
        return (double) sum / scores.length;
    }
}