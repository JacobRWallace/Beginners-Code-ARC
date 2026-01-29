package ClassWork102824;

public class TTU_StudentDemo {

	public static void main(String args[]) {
		
		// Create students (objects)
		TTU_Student std1 = new TTU_Student();
		TTU_Student std2 = new TTU_Student();
		
		// Set values of std1 attributes
		std1.setname("Bob Ferguson");
		std1.setscore(92.5);
		std1.setpassfail(true);
		
		// Set values of std2 attributes
		std2.setname("Jim Apples");
		std2.setscore(66.2);
		std2.setpassfail(false);
		
		// Print std1 attributes
		System.out.println("Student 1 Information:");
		System.out.println("Name: " + std1.getname());
		System.out.println("Score: " + std1.getscore());
		System.out.println("Status: " + (std1.getpassfail() ? "Pass" : "Fail")); // If statement: true = Pass, false = Fail
		System.out.println("College: " + TTU_St1.college); // Print String
		
		// Break line
		System.out.println();
		
		// Print std2 attributes
		System.out.println("Student 2 Information:");
		System.out.println("Name: " + std2.getname());
		System.out.println("Score: " + std2.getscore());
		System.out.println("Status: " + (std2.getpassfail() ? "Pass" : "Fail")); // If statement: true = Pass, false = Fail
		System.out.println("College: " + TTU_St1.college); // Print String
		
	}
}
