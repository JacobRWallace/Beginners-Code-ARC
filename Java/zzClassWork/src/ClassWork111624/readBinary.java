package ClassWork111624;

import java.io.*;

public class readBinary {
    public static void main(String[] args) throws IOException {
        FileInputStream fstream = new FileInputStream("myfile002.dat");
        DataInputStream outputfile = new DataInputStream(fstream);

        int a;
        boolean endoffile = false;

        while (!endoffile) {
            try {
                a = outputfile.readInt();
                System.out.println(a);
            } catch (EOFException e) {
                endoffile = true;
            }
        }

        outputfile.close();
    }
}
