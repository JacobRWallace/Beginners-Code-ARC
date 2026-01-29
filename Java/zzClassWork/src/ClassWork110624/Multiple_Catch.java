package ClassWork110624;

//import java.util.Scanner;

public class Multiple_Catch {

 public static void main(String[] args) {
     // TODO Auto-generated method stub
     int a = 1;
     try {
         int b = 20 / a;
         int[] c = {10, 20, 24};
         c[10] = 34;
     } catch (ArithmeticException | ArrayIndexOutOfBoundsException e) {
         System.out.println(e);
     }
     System.out.println("PROGRAM IS FINISHED");
 }
}
