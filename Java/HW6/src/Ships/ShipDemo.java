package Ships;

public class ShipDemo {
    public static void main(String[] args) {
        // Create array of Ship objects
        Ship[] ships = new Ship[3];

        // Initialize the array with Ship, CruiseShip, and CargoShip
        ships[0] = new Ship("Titanic", "1909");
        ships[1] = new CruiseShip("Blackbeard", "2003", 6432);
        ships[2] = new CargoShip("Fishing Boat", "2012", 120000);

        // Go through array and display ship's details with toString
        for (Ship ship : ships) {
            System.out.println(ship.toString());
        }
    }
}