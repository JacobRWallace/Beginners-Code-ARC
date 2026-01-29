package problem1;

abstract public class House {
	 protected String type;
	 protected String location;

	
	//Constructor
	public House(String type, String location) {
	    this.type = type;
	    this.location = location;
	}
	
	//constructor no arguments
    public House() {
        this.type = "Unknown"; 
        this.location = "Unknown";
    } 
	
	//setter methods
    public void setType(String type) { 
        this.type = type; 
    }  
  
    public void setLocation(String location) { 
        this.location = location; 
    }
 
	//abstracted getter methods
    public abstract String getType();
    public abstract String getLocation();
	
	public static void main(String[] args) {
		
	}
}
