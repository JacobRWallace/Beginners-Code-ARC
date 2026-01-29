package p_10_11_24_001;

public class Rectangle {
	private double length;
	private double width;
	
	//Parameterized Constructor using super initialize our values
	public Rectangle(double length, double width) {
		this.length = 0;
		this.width = 0;
	}
	
	public void setWidth(double w) {
		width=w;
	}
	public double getWidth() {
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