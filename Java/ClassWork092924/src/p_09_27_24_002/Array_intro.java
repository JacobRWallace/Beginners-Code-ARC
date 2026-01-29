package p_09_27_24_002;

import java.util.Scanner;

public class Array_intro {

    public static void main(String[] args) {
        Scanner keyboard = new Scanner(System.in);

        System.out.println("Enter the length for the double array:");
        int length = keyboard.nextInt();

        int[] a = new int[20];
        int len = 20;
        float[] f = new float[len];
        int len1 = 10;
        double[] d = new double[len1];
        final int len2 = 10;
        int[] b = new int[len2];

        int len3 = 10;
        int[] c = new int[len2];
        len3 = 50;
        System.out.println("The array length is: " + c.length);

        for (int i = 0; i < c.length; i++) {
            System.out.println("c[" + i + "] = " + c[i]);
        }

        c[9] = 90;
        c[0]++;
        c[5] = 5 * 4;
        ++c[1];

        System.out.println("\nModified array 'c':");
        for (int i = 0; i < c.length; i++) {
            System.out.println("c[" + i + "] = " + c[i]);
        }

        double[] d1 = new double[length];
        System.out.println("\nDouble array d1:");
        for (int i = 0; i < d1.length; i++) {
            System.out.println("d1[" + i + "] = " + d1[i]);
        }

        double[] d11 = new double[length];
        for (int i = 0; i < d11.length; i++) {
            d11[i] = Math.random() * 100;
        }

        System.out.println("\nArray d11 (with random values):");
        for (double value : d11) {
            System.out.println(value);
        }

        char[] c1 = {'a', 'b', 'd', 'g', 'f'};
        System.out.println("\nChar array c1:");
        for (char i : c1) {
            System.out.print(i + " ");
        }
        System.out.println();

        int length1 = c1.length;
        char[] c11 = new char[length1];
        for (int i = 0; i < c11.length; i++) {
            c11[i] = c1[i];
        }

        System.out.println("\nCopied char array c11:");
        for (char i : c11) {
            System.out.print(i + " ");
        }
        System.out.println();

        int[] r = {1, 2, 45, 67, 89, 200};
        System.out.println("\nInteger array 'r':");
        printarray(r);

        char[] e = getArray();
        System.out.println("\nChar array returned from getArray:");
        for (char i : e) {
            System.out.println(i);
        }

        keyboard.close();
    }

    public static void printarray(int[] array) {
        for (int i = 0; i < array.length; i++) {
            System.out.println(array[i]);
        }
    }

    public static char[] getArray() {
        char[] c = {'a', 'd', 'g', 'h', 'k'};
        return c;
    }
}
