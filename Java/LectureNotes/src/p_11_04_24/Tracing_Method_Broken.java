package p_11_04_24;

// Code example where try-catch block method would be needed.
public class Tracing_Method_Broken {
	public static void main(String args[]) {
		//TODO Auto-generated method stub
		myMethod();
		
	}
	public static void myMethod() { // Method to call produceError method.
		System.out.println('Calling "produceError" Function...');
		produceError();
	}
	public static void produceError() { // Method to intentionally create an error.
		String str = "abc";
		System.out.println(str.charAt(3)); // Tries to call 4th element in the array; giving an error.
		System.out.println('"produceError" Completed.')
	}
}