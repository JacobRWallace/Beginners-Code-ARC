package ClassWork102124;

public class CompScStd extends Student {
	
	// Variables
	private int mathHours;
	private int csHours;
	private int genEdHours;
	
	// Constructor (Doesn't have a return type.)
	public CompScStd(String n, String id, int year, int mH, int cH, int gH)
	{
		super(n,id,year);
		mathHours = mH;
		csHours = cH;
		genEdHours = gH;
	}
	
	public int getRemainingHours()
	{
		return 126-mathHours-csHours-genEdHours;
	}
}
