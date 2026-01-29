package ClassWork110624;

public class Exception {

    public static void main(String[] args) {
        // TODO Auto-generated method stub
        int[] a = {1, 2, 3};
        try {
            System.out.println(a[0]);
        } catch (ArrayIndexOutOfBoundsException b) {
            System.out.println(b);
        } finally {
            System.out.println("how are you?");
        }
    }
}
