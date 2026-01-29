package p_11_04_24;

// Fixed by using try-catch block method.
public class Tracing_Method_Fixed_Throw {
	public static void main(String args[]) {
		//TODO Auto-generated method stub
		myMethod();
		
	}
	public static void myMethod() { // Method to call produceError method.
		System.out.println("Calling produceError Function...");
		produceError();
	}
	public static void produceError() { // Method to intentionally create an error.
		String str = "abc";
		try {
		System.out.println(str.charAt(3)); // Tries to call 4th element in the array; giving an error.
		} catch(StringIndexOutOfBoundsException e) {
			System.out.println(e);
		}
		System.out.println("produceError Completed.");
	}
}