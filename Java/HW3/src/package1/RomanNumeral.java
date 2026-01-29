package package1;

import java.util.Scanner;

public class RomanNumeral {

    // Function that converts number into Roman numeral
    public static void toRoman(int number) {
        String[] romanNumerals = { //Library (list) of roman numerals to be printed from number inputed.
            "XC", "LXXX", "LXX", "LX", "L", "XL", "XXX", "XX", "X",
            "IX", "VIII", "VII", "VI", "V", "IV", "III", "II", "I"
        };
        int[] numbers = { //Library (list) of numbers that are represented by roman numerals.
            90, 80, 70, 60, 50, 40, 30, 20, 10,
            9, 8, 7, 6, 5, 4, 3, 2, 1
        };

        for (int i = 0; i < numbers.length; i++) { //For loop for each number in the numbers list
            while (number >= numbers[i]) { //Find the biggest roman numeral value that can be represented in the number input.
                System.out.print(romanNumerals[i]);
                number -= numbers[i]; //Subtract largest roman numeral value from input and store new value back into number variable to print off remaining values to represent input.
            }
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int number = 0; 

        //Input loop and verifying valid input
        while (true) {
            System.out.print("Enter a number between 1 and 90: ");
            if (scanner.hasNextInt()) {
                number = scanner.nextInt(); //Store input
                if (number >= 1 && number <= 90) {
                    //Convert to Roman numeral and display result
                	System.out.print(number + " -> ");
                    toRoman(number);
                    System.out.println("");
                } else {
                    System.out.println("Invalid input. Please enter a number between 1 and 90.");
                }
            } else {
                System.out.println("Invalid input. Please enter a valid integer.");
                scanner.next(); //Erase Invalid input
            }
        }
    }
}
