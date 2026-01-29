// Abstract class Shape
package package1;

abstract class Shape {
    String shape;

    // Method to set the shape name
    public void setShape(String shape) {
        this.shape = shape;
    }

    // Abstract method to get the shape name
    public abstract String getShape();
}

// Interface Tr1_Wallace
interface Tr1_Wallace {
    // Default method that prints "Triangle Interface"
    default void printName() {
        System.out.println("Triangle Interface");
    }
}

// Interface Triangle_Wallace that extends Tr1_Wallace
interface Triangle_Wallace extends Tr1_Wallace {
    // Setter methods for each side
    void setSide1(double side1);
    void setSide2(double side2);
    void setSide3(double side3);

    // Getter methods for each side
    double getSide1();
    double getSide2();
    double getSide3();
}

// Class Triangle that implements Triangle_Wallace and inherits Shape
class Triangle extends Shape implements Triangle_Wallace {
    private double side1;
    private double side2;
    private double side3;

    // Constructor to initialize all three sides
    public Triangle(double side1, double side2, double side3) {
        this.side1 = side1;
        this.side2 = side2;
        this.side3 = side3;
    }

    // No-arg constructor
    public Triangle() {
        this(0, 0, 0); // Initialize sides to 0
    }

    // Copy constructor
    public Triangle(Triangle other) {
        this(other.side1, other.side2, other.side3);
    }

    // Implementation of printName method (overrides interface method)
    @Override
    public void printName() {
        System.out.println("Triangle Class");
    }

    // Implement the setter methods
    @Override
    public void setSide1(double side1) {
        this.side1 = side1;
    }

    @Override
    public void setSide2(double side2) {
        this.side2 = side2;
    }

    @Override
    public void setSide3(double side3) {
        this.side3 = side3;
    }

    // Implement the getter methods
    @Override
    public double getSide1() {
        return side1;
    }

    @Override
    public double getSide2() {
        return side2;
    }

    @Override
    public double getSide3() {
        return side3;
    }

    // Implement the abstract method getShape from Shape
    @Override
    public String getShape() {
        return "Triangle";
    }
}

// Class TriangleCL1 that inherits Triangle
class TriangleCL1 extends Triangle {
    // Parameterized constructor
    public TriangleCL1(double side1, double side2, double side3) {
        super(side1, side2, side3);
    }

    // No-arg constructor
    public TriangleCL1() {
        super(); // Calls the no-arg constructor of Triangle
    }
}
