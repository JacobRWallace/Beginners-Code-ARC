package package1;

public class Triangle implements Triangle_Wallace {
	
	private static double side1;
	private static double side2;
	private static double side3;
	
	public Triangle() {
		side1 = 0;
		side2 = 0;
		side3 = 0;
	}
	
	public Triangle(double s1, double s2, double s3) {
		this.side1 = s1;
		this.side3 = s2;
		this.side3 = s3;
	}
	
	public Triangle(Triangle test) {
		this.side1 = test.side1;
		this.side2 = test.side2;
		this.side3 = test.side3;
	}
	
	
	
}


/*
Design an abstract class named Shape with the following specifications:
- A field named shape of type String
- One method named setShape that takes a String input
- One public abstract method named getShape that returns the shape name

Design an interface named Tr1_Wallace with:
- A single default method printName that prints "Triangle Interface"

Design another interface, Triangle_Wallace, that:
- Inherits Tr1_Wallace
- Defines three setter methods for three sides and three getter methods that return each side's value

Design a class Triangle that:
- Implements the Triangle_Wallace interface
- Inherits the Shape class
- Has three private fields (three sides) as double
- Includes a constructor to initialize these fields
- Includes a no-arg constructor and a copy constructor
- Defines a printName method that prints "Triangle Class"
- Provides implementations for all inherited methods

Design a class TriangleCL1 that:
- Inherits the Triangle class
- Includes a parameterized constructor to initialize side lenghts
- Includes a no-arg constructor
*/