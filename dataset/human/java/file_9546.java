//Created by Aminul on 9/19/2020.

import java.io.*;
import java.util.*;

import static java.lang.Math.*;

public class Main {
    public static void main(String[] args) throws Exception {
        Scanner in = new Scanner(System.in);
        PrintWriter pw = new PrintWriter(System.out);

        int n = in.nextInt();
        int x[] = new int[n], y[] = new int[n];
        for (int i = 0; i < n; i++) {
            x[i] = in.nextInt();
            y[i] = in.nextInt();
        }

        boolean flag = false;
        for (int i = 2; i < n; i++) {
            flag |= (x[i] == y[i] && x[i - 1] == y[i - 1] && x[i - 2] == y[i - 2]);
        }

        pw.println(flag ? "Yes" : "No");


        pw.close();
    }

    static void debug(Object... obj) {
        System.err.println(Arrays.deepToString(obj));
    }
}
