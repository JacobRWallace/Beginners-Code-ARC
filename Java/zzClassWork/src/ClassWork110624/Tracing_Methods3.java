package ClassWork110624;

public class Tracing_Methods3 {

    public static void main(String[] args) {
        // TODO Auto-generated method stub
        System.out.println("Calling myMethod");
        myMethod();
        System.out.println("myMethod is done");
    }

    public static void myMethod() {
        System.out.println("Calling produceError");
        try {
            produceError();
        } catch (StringIndexOutOfBoundsException e) {
            System.out.println(e.getMessage());
        }
        System.out.println("produceError is done");
    }

    public static void produceError() {
        String str = "abc";
        System.out.println(str.charAt(3)); // This line will throw an exception
        System.out.println("produceError is done");
    }
}
