/**
 * This program plays a word game where the user inputs various details,
 * and the program creates a fun story by inserting the user's input into it.
 * Author: Jacob Wallace
 * Date: 9/14/24
 */
import java.util.Scanner;

public class WordGame {
    public static void main(String[] args) {
        // Create a Scanner object to capture user input
        Scanner scanner = new Scanner(System.in);

        // Ask for user's name
        System.out.print("Enter your name: ");
        String name = scanner.nextLine(); // Storing user's name
        
        // Ask for user's age
        System.out.print("Enter your age: ");
        int age = scanner.nextInt(); // Storing user's age
        scanner.nextLine(); // Consume the newline left by nextInt

        // Ask for city name
        System.out.print("Enter the name of a city: ");
        String city = scanner.nextLine(); // Storing city name

        // Ask for college name
        System.out.print("Enter the name of a college: ");
        String college = scanner.nextLine(); // Storing college name

        // Ask for profession
        System.out.print("Enter a profession: ");
        String profession = scanner.nextLine(); // Storing profession

        // Ask for type of animal
        System.out.print("Enter a type of animal: ");
        String animal = scanner.nextLine(); // Storing animal type

        // Ask for pet's name
        System.out.print("Enter a pet's name: ");
        String petName = scanner.nextLine(); // Storing pet's name

        // Display the final story with the user's input
        System.out.println("There once was a person named " + name + " who lived in " + city + ".");
        System.out.println("At the age of " + age + ", " + name + " went to college at " + college + ".");
        System.out.println(name + " graduated and went to work as a " + profession + ".");
        System.out.println("Then, " + name + " adopted a(n) " + animal + " named " + petName + ".");
        System.out.println("They both lived happily ever after!");

        scanner.close();
    }
}