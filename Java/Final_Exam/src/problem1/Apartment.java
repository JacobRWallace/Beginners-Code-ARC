package problem1;

class Apartment extends House implements HouseDetails {
	
	//variables
    private int numberOfRooms;
    private boolean hasBalcony;

    //parameterized constructor
    public Apartment(String type, String location, int numberOfRooms, boolean hasBalcony) {
        super(type, location);
        this.numberOfRooms = numberOfRooms;
        this.hasBalcony = hasBalcony;
    }

    //default constructor
    public Apartment() {
        super();
        this.numberOfRooms = 0;
        this.hasBalcony = false;
    }

    //getters and setters
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

    public String getType() {
        return super.type;
    }

    public String getLocation() {
        return super.location;
    }

    //methods from HouseDetails
    public String toString() {
        return "Apartment Type: " + getType() + ", Location: " + getLocation() + ", Rooms: " + getNumberOfRooms() + ", Balcony: " + (hasBalcony ? "Yes" : "No");
    }
    
    
}