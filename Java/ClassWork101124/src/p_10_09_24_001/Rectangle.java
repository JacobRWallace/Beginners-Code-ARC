package p_10_09_24_001;

public class Rectangle {
	private double height;
	private double length;
	
    // Added Constructor
    public Rectangle(double height, double length) {
        this.height = height; // Initialize the height from the existing Rectangle
        this.length = length; // Initialize the length  from the existing Rectangle
    }
    
    // Added Copy Constructor
    public Rectangle(Rectangle r) {
        this.height = r.height; // Copy the height from the existing Rectangle
        this.length = r.length;  // Copy the length from the existing Rectangle
    }
	
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