package Ships;

/**
 * Represents a cruise ship with a maximum passenger capacity.
 */
public class CruiseShip extends Ship {
    public int maxPassengers; // Maximum number of passengers

    // Constructor
    public CruiseShip(String name, String yearBuilt, int maxPassengers) {
        super(name, yearBuilt);
        this.maxPassengers = maxPassengers;}

    // Accessor and mutator methods
    public int getMaxPassengers() {
        return maxPassengers;}
    public void setMaxPassengers(int maxPassengers) {
        this.maxPassengers = maxPassengers;}

    // Override toString method
    @Override
    public String toString() {
        return "Cruise Ship Name: " + getName() + ", Max Passengers: " + maxPassengers;}
}
