package package1;

import java.util.Scanner;

/**
 * This class generates a bar chart representing sales for 5 stores.
 * Each bar is represented by asterisks where each asterisk represents $100.
 * 
 * @author Jacob Wallace
 * @date 10/01/24
 */

public class BarChart {

    public static void main(String[] args) {
        // Create a Scanner object to get user input
        Scanner scanner = new Scanner(System.in);
        
        // Array to store sales for 5 stores
        int[] sales = new int[5];
        
        // Get sales input for each store
        for(int i = 0; i<5; i++) {
            System.out.print("Enter today's sales for store " + (i+1) + ": $");
            sales[i] = scanner.nextInt();  // Store sales input
        }
        
        // Generate and display the bar chart
        for(int i = 0; i<5; i++) {
            System.out.print("Store " + (i+1) + ": ");
            // Print one asterisk for every $100 in sales
            for (int j = 0; j<sales[i] / 100; j++) {
                System.out.print("*");
            }
            System.out.println();  // Move to the next line after printing the bar
        }
    }
}
