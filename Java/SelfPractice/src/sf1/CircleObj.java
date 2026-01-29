package sf1;
import java.lang.Math;

public class CircleObj {
	private double circumference;
	
	public double getCircum() {
		return circumference;
	}
	
	public void calcCircum(double r) {
		do{
			System.out.print("Error: Enter non-negative input!");
		}while(r<0);
		circumference = 2*Math.PI*r;
	}
}
