package p_10_11_24_001;

public class Rectangle {
	private double length;
	private double width;
	
	public void setWidth(double w) {
		width=w;
	}
	public double getwidth() {
		return width;
	}
	public void setLength(double l) {
		length=l;
	}
	public double getLength() {
		return length;
	}
	public double getArea() {
		return length*width;
	}
}