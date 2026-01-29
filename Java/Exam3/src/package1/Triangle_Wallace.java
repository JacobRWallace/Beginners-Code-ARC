package package1;

public interface Triangle_Wallace extends Tr1_Wallace {
	
	// Setter Methods
	public default void set1(double i1) {
		side1 = i1;
	}
	
	public default void set2(double i2) {
		side2 = i2;
	}
	
	public default void set3(double i3) {
		side3 = i3;
	}
	
	// Getter Methods
	public default void get1() {
		return side1;
	}
	
	public default void get2() {
		return side2;
	}
	
	public default void get3() {
		return side3;
	}
	
	
}
