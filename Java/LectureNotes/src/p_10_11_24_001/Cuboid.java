package p_10_11_24_001;

public class Cuboid extends Rectangle {
	private double height;
	
	//Parameterized Constructor using super initialize our values
	public Cuboid(double len, double w, double h) {
		super(len,w);
		height=h;
	}
	
	//THIS IS NOT A DEFAULT CONSTRUCTOR it is a no-argument constructor.
	public Cuboid() {
		super(1,1);
		height=1;
	}
	
	public void setHeight(double h) {
		height = h;
	}
	public double getHeight() {
		return height;
	}
	public double getVolume() {
		double volume;
		volume = super.getLength()*super.getWidth()*height;
		return volume;
	}
	
}