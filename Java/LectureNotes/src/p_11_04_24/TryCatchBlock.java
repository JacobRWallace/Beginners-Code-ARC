package p_11_04_24;

public class TryCatchBlock {
	public static void main(String args[]) {
		//TODO Auto-generated method stub
		int[] a = {1,2,45};
		try {
			System.out.println("a[0]: " + a[0]);
		} catch (ArrayIndexOutOfBoundsException b) {
			System.out.println("b: " + b);
		}
	}
}
