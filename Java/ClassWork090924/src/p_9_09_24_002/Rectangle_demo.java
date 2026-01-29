package p_9_09_24_002;

public class Rectangle_demo {

	public static void main(String[] args)
	{
		Rectangle_ r1=new Rectangle_();
		//r1.height=20;
		r1.setHeight(17);
		r1.setLength(32.5);
		System.out.println("The height of rectangle r1"+" is "+r1.getHeight());
		System.out.println("The length of rectangle r1"+" is "+r1.getLength());
		System.out.println("The area of rectangle r1"+" is "+r1.getArea());
	}
}