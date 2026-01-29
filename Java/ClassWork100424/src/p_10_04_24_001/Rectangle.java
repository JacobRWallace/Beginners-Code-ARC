package p_10_04_24_001;

public class Rectangle {
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