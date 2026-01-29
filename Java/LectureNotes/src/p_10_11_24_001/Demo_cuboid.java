package p_10_11_24_001;

public class Demo_cuboid {
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Cuboid c = new Cuboid();
		c.setLength(5);
		c.setWidth(10);
		System.out.println("The area is " + c.getArea());
		
		c.setHeight(5);
		System.out.println("The volume is " + c.getVolume());
	}
}
