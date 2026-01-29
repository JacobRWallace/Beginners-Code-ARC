package package1;

import java.util.Scanner;

public class SortedNames {
	
	public static void main(String[] args) {
		
		String[] temp = { //Array to store names
			"NA", "NA", "NA"};
		
		Scanner scanner = new Scanner(System.in);
		System.out.print("Enter name 1: "); // Store name1 from input
		temp[0] = scanner.next();
		
		System.out.print("Enter name 2: "); // Store name2 from input
		temp[1] = scanner.next();
		
		System.out.print("Enter name 3: "); // Store name3 from input
		temp[2] = scanner.next();
		
		System.out.println("Names in alphabetical order:");
		for (int j=0; j<36; j++) { // Increment alphabetical letter value from a - z
			for (int i=0; i<3; i++) { // Increment list index
				if (j == Character.getNumericValue(temp[i].charAt(0))) {
					System.out.println(temp[i]);
				}
			}
		}
	}
}