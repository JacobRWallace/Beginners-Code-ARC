package p_9_23_24;

package java.lang.Math;

public class Circle {
	private double radius;
	private double area;
	private double circumference;
	
	public double getRadius() {						//Method
		return radius;
	}
	
	public Circle(double radius) {					//Constructor w/ Argument
		this.radius=radius;
	}
	
	public void setArea(double radius) {			//Method
		this.area = Math.PI * Math.pow(radius, 2);
	}
	
	public void setC(double circumference) {		//Method
		this.circumference = circumference / 2 * Math.PI;
	}

	public void getC() {							//Method
		return circumference;
	}
	
	public void setRadius(double radius) {
		this.radius = radius;
	}
	
	public double getArea() {						//Method
		return area;
	}
	
	public Circle(Circle r) {						//Initialize Constructor
		this.radius=r.radius;
	}
	
	public Circle() {								//No Arg. Constructor
		radius=0;
	}
}

