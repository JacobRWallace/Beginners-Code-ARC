package ClassWork102124;

public abstract class Student {
	
	// Variables
	private String name;
	private String Rnumber;
	private int yearAdmitted;
	
	// Constructor (Doesn't have a return type.)
	public Student(String n, String id, int year) {
		name=n;
		Rnumber=id;
		yearAdmitted=year;
	}
	
	public abstract int getRemainingHours();
		
}
