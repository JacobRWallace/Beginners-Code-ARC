package p1;

import p1.Shape;
import p1.Triangle;
import p1.Triangle_Wallace;


// i don't think this is right.

class Triangle extends Shape implements Triangle_Wallace {
	private double side1;
	private double side2;
	private double side3;
	
	// constructor that initializes all three sides
	public Triangle(double side1, double side2, double side3) {
		this.side1 = side1;
		this.side2 = side2;
		this.side3 = side3;
	}
	
	// no-arg constructor
	public Triangle() {
		this(0, 0, 0);
	}

	public Triangle(Triangle other) {
		this(other.side1, other.side2, other.side3);
	}

	public void printName() {
		System.out.println("Triangle Class");
	}

	public void setSide1(double side1) {
		this.side1 = side1;
	}

	public void setSide2(double side2) {
		this.side2 = side2;
	}

	public void setSide3(double side3) {
		this.side3 = side3;
	}

	public double getSide1() {
		return side1;
	}
	
	public double getSide2() {
		return side2;
	}
	
	public double getSide3() {
		return side3;
	}

	public String getShape() {
		return "Triangle";
	}
}