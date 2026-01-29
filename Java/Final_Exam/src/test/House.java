// Abstract class House
abstract class House {
    private String type;
    private String location;

    // Parameterized constructor
    public House(String type, String location) {
        this.type = type;
        this.location = location;
    }

    // Default constructor
    public House() {
        this.type = "Unknown";
        this.location = "Unknown";
    }

    // Setter methods
    public void setType(String type) {
        this.type = type;
    }

    public void setLocation(String location) {
        this.location = location;
    }

    // Abstract getter methods
    public abstract String getType();

    public abstract String getLocation();
}

// Interface HouseDetails
interface HouseDetails {
    void setNumberOfRooms(int numberOfRooms);

    int getNumberOfRooms();
}

// Class Apartment
class Apartment extends House implements HouseDetails {
    private int numberOfRooms;
    private boolean hasBalcony;

    // Parameterized constructor
    public Apartment(String type, String location, int numberOfRooms, boolean hasBalcony) {
        super(type, location);
        this.numberOfRooms = numberOfRooms;
        this.hasBalcony = hasBalcony;
    }

    // Default constructor
    public Apartment() {
        super();
        this.numberOfRooms = 0;
        this.hasBalcony = false;
    }

    // Getters and setters
    public void setNumberOfRooms(int numberOfRooms) {
        this.numberOfRooms = numberOfRooms;
    }

    public int getNumberOfRooms() {
        return numberOfRooms;
    }

    public void setHasBalcony(boolean hasBalcony) {
        this.hasBalcony = hasBalcony;
    }

    public boolean isHasBalcony() {
        return hasBalcony;
    }

    // Implementing abstract methods from House
    @Override
    public String getType() {
        return super.type;
    }

    @Override
    public String getLocation() {
        return super.location;
    }

    // Implementing methods from HouseDetails
    @Override
    public String toString() {
        return "Apartment Type: " + getType() + ", Location: " + getLocation() + ", Rooms: " + getNumberOfRooms() + ", Balcony: " + (hasBalcony ? "Yes" : "No");
    }
}

// Demo class HouseDemo
public class HouseDemo {
    public static void main(String[] args) {
        // Instantiate an Apartment object
        Apartment apartment = new Apartment("Apartment", "City Center", 3, true);

        // Print the apartment details
        System.out.println(apartment);
    }
}
