/*
 * This program processes the user's favorite car model and displays
 * various properties like character count, uppercase, lowercase, and first character.
 * Author: Jacob Wallace
 * Date: 9/14/24
 */
import java.util.Scanner;

public class FavoriteCar
{
    public static void main(String[] args)
    {
    	// Create a Scanner object to capture user input
        Scanner scanner = new Scanner(System.in);

        // Ask the user for their favorite car model
        System.out.print("Enter the name of your favorite car model: ");

        // Store the user's input in a String variable
        String carModel = scanner.nextLine(); // Single-line comment: storing car model

        // Display the number of characters in the car name
        System.out.println("Number of characters: " + carModel.length());

        // Display the car name in all uppercase letters
        System.out.println("Uppercase: " + carModel.toUpperCase());

        // Display the car name in all lowercase letters
        System.out.println("Lowercase: " + carModel.toLowerCase());

        // Display the first character of the car model
        System.out.println("First character: " + carModel.charAt(0));

        scanner.close();
    }
}