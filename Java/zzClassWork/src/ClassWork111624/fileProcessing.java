package ClassWork111624;

import java.io.*;
import java.util.Scanner;

public class fileProcessing {
    public static void main(String[] args) throws FileNotFoundException {
        PrintWriter file = new PrintWriter("Student001.txt");
        file.println("John");
        file.println("David");
        file.println("Anna");
        file.close();

        // Reading a file
        File file2 = new File("Student001.txt");
        Scanner inputfile = new Scanner(file2);

        String str = inputfile.nextLine();
        System.out.println(str);

        str = inputfile.nextLine();
        System.out.println(str);

        str = inputfile.nextLine();
        System.out.println(str);

        inputfile.close();
    }
}
