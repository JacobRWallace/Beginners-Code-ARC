package p_9_09_24_002;

public class Rectangle_ {
	private double height;
	private double length;
	
	public void setHeight(double h) {
		height=h;
	}
	public double getHeight() {
		return height;
	}
	public void setLength(double l) {
		length=l;
	}
	public double getLength() {
		return length;
	}
	public double getArea() {
		return length*height;
	}
}