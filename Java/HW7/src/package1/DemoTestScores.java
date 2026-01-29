package package1;

/**
 * demonstrates test scores java program
 * @author Jacob Wallace
 * @date 11/15/24
 */
public class DemoTestScores {
    public static void main(String[] args) {
        try {
            // valid test scores
            int[] validScores = {90, 85, 78, 92, 88};
            TestScores testScores = new TestScores(validScores);
            System.out.println("Average of valid scores: " + testScores.getAverage());

            // invalid test scores
            int[] invalidScores = {100, 110, -5, 95};
            TestScores invalidTestScores = new TestScores(invalidScores); // This will throw an exception

        } catch (InvalidTestScores e) {
            System.out.println("InvalidTestScore exception caught: " + e.getMessage());
        }

        try {
            // Another invalid set of scores
            int[] anotherInvalidScores = {50, 60, -10, 80};
            TestScores testScores2 = new TestScores(anotherInvalidScores); // This will throw an exception
        } catch (InvalidTestScores e) {
            System.out.println("InvalidTestScore exception caught: " + e.getMessage());
        }
    }
}
