package p_10_04_24_001;

public class Array_Intro {

    public static void main(String[] args) {
    	
    	// TODO Auto-generated method stub
        int[] a = new int[20];
        double[] d = new double[100];
        int len1;
        int len = 10;
        int[] b = new int[len];

        final int len2 = 10;
        double[] d1 = new double[len2];

        for (int i = 0; i < len2; i++) {
            d[i] = i;
            System.out.println("d[" + i + "]=" + d[i]);
        }

        d[9] = (++d[0] + 89);
        for (int i = 0; i < len2; i++) {
            System.out.println("d[" + i + "]=" + d[i]);
        }

        int len3 = 10;
        double[] d2 = new double[len3];
        len3 = 100;
        System.out.println(d2.length);

        for (int i = 0; i < d2.length; i++) {
            System.out.println("d2[" + i + "]=" + d2[i]);
        }

        for (double i : d2) {
            System.out.println(i);
        }

        int len4 = d2.length;
        double[] d3 = new double[len4];

        for (int i = 0; i < len; i++) {
            d3[i] = d2[i];
        }

        int[] a1 = {23, 34, 67, 0, 32};
        printArray(a1);

        double[] d21 = getArray();
        for (double i : d21) {
            System.out.println(i);
        }
    }

    public static void printArray(int[] array) {
        for (int i = 0; i < array.length; i++) {
            System.out.println(array[i]);
        }
    }

    public static double[] getArray() {
        double[] d = {34, 56, 78, 90};
        return d;
    }
}
