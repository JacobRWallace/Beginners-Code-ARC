package ClassWork111624;

import java.io.*;

public class randomAccess2 {
    public static void main(String[] args) throws IOException {
        RandomAccessFile file = new RandomAccessFile("random.dat", "rw");
        char c;

        file.seek(4);
        c = file.readChar();
        System.out.println(c);
        
        file.seek(1);
        c = file.readChar();
        System.out.println(c);
        
        file.seek(2);
        c = file.readChar();
        System.out.println(c);

        file.close();
    }
}
