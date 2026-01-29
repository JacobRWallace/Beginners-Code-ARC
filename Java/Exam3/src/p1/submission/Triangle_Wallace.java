package p1;

import p1.Tr1_Wallace;

interface Triangle_Wallace extends Tr1_Wallace {
	
	// setter methods
	void setSide1(double side1);
	void setSide2(double side2);
	void setSide3(double side3);
	
	// getter methods
	double getSide1();
	double getSide2();
	double getSide3();
}