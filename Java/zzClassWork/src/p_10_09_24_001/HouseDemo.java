package p_10_09_24_001;

public class HouseDemo {
	
	public static void main(String[] args) {
		
		//TODO Auto-generated method stub
		House h1 = new House(2);
		h1.addRooms(new Rectangle(5,5));
		h1.addRooms(new Rectangle(2,10));
		double area = h1.getRooms(0).getArea();
		
		System.out.println(area);
		
	}
}
