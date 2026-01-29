package Ships;

/**
 * Represents a cargo ship with a cargo capacity in tonnage.
 */
public class CargoShip extends Ship {
    public int cargoCapacity; // Cargo capacity variable

    // Constructor
    public CargoShip(String name, String yearBuilt, int cargoCapacity) {
        super(name, yearBuilt);
        this.cargoCapacity = cargoCapacity;}

    // Accessor and mutator for cargoCapacity
    public int getCargoCapacity() {
        return cargoCapacity;}
    public void setCargoCapacity(int cargoCapacity) {
        this.cargoCapacity = cargoCapacity;}

    // Override toString method
    @Override
    public String toString() {
        return "Cargo Ship Name: " + getName() + ", Cargo Capacity: " + cargoCapacity + " tons";}
}
