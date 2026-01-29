/*
 * This program creates Rectangles and prints the dimensions of the created Rectangles.
 * Author: Jacob Wallace
 * Date: 9/17/24
 */

package p_9_16_24_001;

public class RectangleDemo {
    public static void main(String[] args) {
    	double len, w;
    	len = 10;
    	w = 20;
    	Rectangle r1 = new Rectangle(len, w);
    	Rectangle r2 = new Rectangle();
    	System.out.println("The lenght of the rectangle r1 is " + r1.getLength());
    	System.out.println("The width of the rectangle r1 is " + r1.getWidth());
    	System.out.println("The lenght of the rectangle r2 is " + r2.getLength());
    	System.out.println("The width of the rectangle r2 is " + r2.getWidth());
    	
    	Rectangle r3 = new Rectangle(r1);
    	System.out.println("The lenght of the rectangle r3 is " + r3.getLength());
    	System.out.println("The width of the rectangle r3 is " + r3.getWidth());
    }
}