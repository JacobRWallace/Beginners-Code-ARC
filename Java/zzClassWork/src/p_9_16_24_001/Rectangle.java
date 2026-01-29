/*
 * This program define the functions needed to set and get the length and width of a rectangle and finding its area.
 * Author: Jacob Wallace
 * Date: 9/17/24
 */

package p_9_16_24_001;

public class Rectangle {
    private double length;
    private double width;
    
    public Rectangle(double len, double w) {
    	length=len;
    	width=w;
    }
    
    public Rectangle() {
    	length=1;
    	width=1;
    }
    
    /*
     * Sets the length of the rectangle @param len the value to be stored in length variable.
     */
    
    public Rectangle(Rectangle r) {
    	length=r.length;
    	width=r.width;
    }
    
    public void setLength(double l) {
    	length=l;
    }
    
    /*
     * Return the length of the rectangle @return return the value of the length variable.
     */
    
    public double getLength() {
    	return length;
    }
    
    /*
     * Set the width of the rectangle @param w the value to be stored in the width variable.
     */
    
    public void setWidth(double w) {
    	width=w;
    }
    
    /*
     * @return the value of width variable.
     */
    
    public double getWidth() {
    	return width;
    }
    
    /*
     * Calculates the area of the rectangle @return the area of the rectangle.
     */
    
    public double getArea() {
    	return width*length;
    }
}