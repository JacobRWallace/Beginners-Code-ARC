package Ships;

/**
 * Represents a generic ship with a name and year built.
 */
public class Ship {
	public String name; // String variable for name
	public String yearBuilt; // String variable for yearBuilt
	
	// Constructor
	public Ship(String name, String yearBuilt) {
		this.name = name;
		this.yearBuilt = yearBuilt;}

	// Accessor and mutator methods
	public String getName() {
		return name;}
	public void setName(String name) {
		this.name = name;}
	public String getYearBuilt() {
		return yearBuilt;}
	public void setYearBuilt() {
		this.yearBuilt = yearBuilt;}
	
	// toString method to display name and yearBuilt
	public String toString() {
		return "Ship Name: " + name + ", Year Built: " + yearBuilt;}
}
