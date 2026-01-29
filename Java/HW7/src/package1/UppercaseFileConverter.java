package package1;

import java.io.*;
import java.util.Scanner;

/**
 * converts all text in one file to uppercase and writes to a separate file
 */
public class UppercaseFileConverter {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter the input file name: ");
        String inputFileName = scanner.nextLine();

        System.out.print("Enter the output file name: ");
        String outputFileName = scanner.nextLine();
        
        // try catch block to catch IOException error
        try (BufferedReader reader = new BufferedReader(new FileReader(inputFileName));
             BufferedWriter writer = new BufferedWriter(new FileWriter(outputFileName))) {

            String line;
            while ((line = reader.readLine()) != null) {
                writer.write(line.toUpperCase());
                writer.newLine();
            }

            System.out.println("File conversion completed successfully.");

        } catch (IOException e) {
            System.out.println("An error occurred: " + e.getMessage());
        }
    }
}