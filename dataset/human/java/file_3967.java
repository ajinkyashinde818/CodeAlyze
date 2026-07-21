import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        PrintWriter cout = new PrintWriter(System.out);

        int n = cin.nextInt();
        int[] a = new int[n];
        for(int i=0;i<n;i++) a[i] = cin.nextInt() - 1;
        int[] b = new int[n];
        for(int i=0;i<n;i++) b[i] = cin.nextInt();
        int[] c = new int[n];
        for(int i=1;i<n;i++) c[i] = cin.nextInt();

        int tot = 0;
        int last = -1;
        for(int i=0;i<n;i++) {
            tot += b[a[i]];
            if(last + 1 == a[i]) tot += c[a[i]];
            last = a[i];
            //cout.println("tot: " + tot);
        }
        cout.println(tot);
        cout.close();
    }
}
