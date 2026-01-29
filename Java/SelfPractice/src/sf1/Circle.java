package sf1;

import java.util.Scanner;

public class Circle {
	public static void main(double[] args) {
		Scanner scanner = new Scanner(System.in);
		CircleObj circle1 = new CircleObj(); //Create a circle object.
		System.out.print("Enter circle radius: ");
		double input = scanner.nextDouble();
		circle1.calcCircum(input);
		System.out.print("Circumference: " + circle1.getCircum());
	}
}
