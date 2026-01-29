package sf1;

import java.util.Scanner; //Import Scanner

public class Class {

	public static void main(String[] args) {
		String[] arr = {"NA", "NA", "NA", "NA", "NA"}; //Create String Array
		
		Scanner scanner = new Scanner(System.in); //Create Scanner Object
		
		for (int i = 0; i<arr.length; i++) {
			System.out.print("Enter String #" + (i+1) + ": ");
			arr[i] = scanner.next();
		}
		
		for (int i = 0; i<arr.length; i++) {
			System.out.println("Index: " + i + " | String: " + arr[i]);
		}
	}
}
