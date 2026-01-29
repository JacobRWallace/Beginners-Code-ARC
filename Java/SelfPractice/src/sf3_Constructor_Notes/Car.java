package sf3_Constructor_Notes;

public class Car {
    String model;
    int year;

    // Default constructor
    public Car() {
        model = "Unknown";
        year = 2020;
    }

    // Parameterized constructor
    public Car(String model, int year) {
        this.model = model;
        this.year = year;
    }

    // Copy constructor
    public Car(Car otherCar) {
        this.model = otherCar.model;
        this.year = otherCar.year;
    }

    // Method to display car details
    public void displayCarInfo() {
        System.out.println("Model: " + model + ", Year: " + year);
    }

    public static void main(String[] args) {
        // Using the default constructor
        Car car1 = new Car();
        car1.displayCarInfo();  // Output: Model: Unknown, Year: 2020

        // Using the parameterized constructor
        Car car2 = new Car("Toyota", 2022);
        car2.displayCarInfo();  // Output: Model: Toyota, Year: 2022

        // Using the copy constructor
        Car car3 = new Car(car2);
        car3.displayCarInfo();  // Output: Model: Toyota, Year: 2022
    }
}
