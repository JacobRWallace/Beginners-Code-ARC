package p_10_09_24_001;

public class House {
	
	private Rectangle[] rooms;
	private int roomnumber;
	
	public House(int n) {
		rooms = new Rectangle[n];
		roomnumber = 0;
	}
	
	public void addRooms(Rectangle r) {
		rooms[roomnumber] = new Rectangle(r);
		roomnumber++;
	}
	
	public Rectangle getRooms(int index) {
		return new Rectangle(rooms[index]);
	}
	
	public double getTotalArea() {
		double area=0;
		for(int i=0; i<rooms.length; i++)
			area += rooms[i].getArea();
		return area;
	}
	
}
