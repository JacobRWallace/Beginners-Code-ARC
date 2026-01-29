package ClassWork111624;

import java.io.*;

public class randomAccess {
    public static void main(String[] args) throws IOException {
        RandomAccessFile file = new RandomAccessFile("random.dat", "rw");
        
        char[] a = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};
        for (int i = 0; i < 4; i++)
            file.writeChar(a[i]);
        
        file.close();
    }
}
