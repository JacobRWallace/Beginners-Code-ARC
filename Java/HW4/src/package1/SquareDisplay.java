package package1;

import java.util.Scanner;

/**
 * This class displays a square of 'X' characters based on user input.
 * The size of the square is determined by a positive integer input (between 1 and 15).
 * 
 * @author Jacob Wallace
 * @date 10/01/24
 */

public class SquareDisplay {

    public static void main(String[] args) {
        // Create a Scanner object to get user input
        Scanner scanner = new Scanner(System.in);
        
        // Continuously prompt for valid input until it is received
        while(true) {
            System.out.print("Enter number from 0-15: ");
            int input = scanner.nextInt();  // Store user input for the square size
            
            // Validate input (must be between 1 and 15)
            if(input > 0 && input < 16) {
                // Print square of 'X' characters with sides equal to the input size
                for(int i = 0; i < input; i++) {
                    for(int j = 0; j < input; j++) {
                        System.out.print("X");  // Print 'X' for each column
                    }
                    System.out.println("");  // Move to the next line after each row
                }
                break;  // Exit the loop after successful input
            } else {
                System.out.println("Invalid input!");  // Notify user of invalid input
            }
        }
    }
}
