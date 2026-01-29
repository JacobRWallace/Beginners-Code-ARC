package p_10_04_24_001;

public class String_Array {

    public static void main(String[] args) {
        String[] names = new String[4];
        System.out.println("Before initialization: " + names[0]);

        names[0] = "Bill";
        names[1] = "John";
        names[2] = "David";
        names[3] = "Jean";
        System.out.println("After initialization: " + names[0]);
        System.out.println(names[3].toUpperCase());
        System.out.println(names[2].toLowerCase());
        System.out.println(names[1].length());

        for (int i = 0; i < names.length; i++) {
            System.out.println(names[i].length());
        }

        Rectangle[] rectangles = new Rectangle[5];
        System.out.println("Before initialization: " + rectangles[0]);

        for (int i = 0; i < rectangles.length; i++) {
            rectangles[i] = new Rectangle();
        }

        System.out.println("After initialization: " + rectangles[0]);
        System.out.println("Area of rectangle 1: " + rectangles[0].getArea());
    }
}
