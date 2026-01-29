package ClassWork111624;

import java.io.*;

public class writeBinary {
    public static void main(String[] args) throws IOException {
        FileOutputStream fstream = new FileOutputStream("myfile002.dat");
        DataOutputStream outputfile = new DataOutputStream(fstream);

        int[] a = {1, 2, 3, 4};
        for (int i = 0; i < 4; i++)
            outputfile.writeInt(a[i]);

        outputfile.writeInt(0);
        outputfile.close();
    }
}
