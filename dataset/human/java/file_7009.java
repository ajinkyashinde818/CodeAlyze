//Created by Aminul on 3/28/2020.

import java.io.*;
import java.util.*;

import static java.lang.Math.*;

public class Main {
    public static void main(String[] args) throws Exception {
        Scanner in = new Scanner(System.in);
        PrintWriter pw = new PrintWriter(System.out);
        int k = in.nextInt(), n = in.nextInt(), res = k;
        int arr[] = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = in.nextInt();
        }
        for (int i = 0; i < n - 1; i++) {
            res = min(res, k - (arr[i + 1] - arr[i]));
        }

        int distanceBetweenFirstAndLast = (arr[0] + (k - arr[n - 1]));
        res = min(res, k - distanceBetweenFirstAndLast);

        pw.println(res);
        pw.close();
    }

    static void debug(Object... obj) {
        System.err.println(Arrays.deepToString(obj));
    }
}
