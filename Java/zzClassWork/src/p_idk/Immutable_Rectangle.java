package p_idk;

final public class Immutable_Rectangle {

    // Fields of the class rectangle
    final private double length;
    final private double width;
    
    // Constructor
    public Immutable_Rectangle(double length, double width) {
        this.length = length;
        this.width = width;
    }

    // No-arg constructor (optional, but usually good to have defaults)
    public Immutable_Rectangle() {
        this.length = 1; // Default value, can be adjusted
        this.width = 1;  // Default value, can be adjusted
    }

    // Copy constructor
    public Immutable_Rectangle(Immutable_Rectangle rr) {
        this.length = rr.length;
        this.width = rr.width;
    }

    // Getter methods (Accessor methods)
    public double getLength() {
        return length;
    }

    public double getWidth() {
        return width;
    }

    public double getArea() {
        return width * length;
    }
}
