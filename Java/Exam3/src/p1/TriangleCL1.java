package p1;

import p1.Triangle;

class TriangleCL1 extends Triangle {
	// parameterized constructor
	public TriangleCL1(double side1, double side2, double side3) {
		super(side1, side2, side3);
	}
	
	// no-arg constructor
	public TriangleCL1() {
		super(); //???
	}
}