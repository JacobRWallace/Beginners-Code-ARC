package ClassWork110624;

public class Tracing_Methods4 {

    public static void main(String[] args) {
        // TODO Auto-generated method stub
        System.out.println("Calling myMethod");
        try {
            myMethod();
        } catch (StringIndexOutOfBoundsException e) {
            System.out.println(e.getMessage());
        }
        System.out.println("myMethod is done");
    }

    public static void myMethod() {
        System.out.println("Calling produceError");
        produceError();
        System.out.println("produceError is done");
    }

    public static void produceError() {
        String str = "abc";
        System.out.println(str.charAt(3)); // This line will cause an error
        System.out.println("produceError is done");
    }
}
