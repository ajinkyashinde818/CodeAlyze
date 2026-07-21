import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        long c = sc.nextLong();
        long[] x = new long[n];
        int[] v = new int[n];
        long[] re = new long[n];
        long[] le = new long[n];
        long[] maxr = new long[n];
        long[] maxl = new long[n];
        for(int i=0; i<n; i++){
            x[i] = sc.nextLong();
            v[i] = sc.nextInt();
        }
        re[0] = v[0] - x[0];
        le[0] = v[n-1] - (c - x[n-1]);

        long max = Math.max(0, Math.max(re[0], le[0]));
        maxr[0] = Math.max(0, re[0]);
        maxl[0] = Math.max(0, le[0]);

        for(int i=1; i<n; i++){
            re[i] = re[i-1] + v[i] - (x[i] - x[i-1]);
            le[i] = le[i-1] + v[n-1-i] - (x[n-i] - x[n-1-i]);
            if(re[i] > max) max = re[i];
            if(le[i] > max) max = le[i];
            maxr[i] = Math.max(re[i], maxr[i-1]);
            maxl[i] = Math.max(le[i], maxl[i-1]);
        }

        for(int i=0; i<n-1; i++){
            long tmp = re[i] + maxl[n-2-i] - x[i];
            if(tmp > max) max = tmp;
            tmp = le[i] + maxr[n-2-i] - (c-x[n-1-i]);
            if(tmp > max) max = tmp;
        }

        System.out.println(max);
    }
}
