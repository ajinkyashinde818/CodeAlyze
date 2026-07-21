import java.util.*;

public class Main {

    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
            int n = sc.nextInt();
            long k = sc.nextLong();
            boolean[] v = new boolean[n];
            long[] s = new long[n];
            int[] a = new int[n];
            for(int i=0; i<n; i++) {
                a[i] = sc.nextInt() - 1;
            }
            v[0] = true;
            long t = 0;
            int pos = 0;
            while(true) {
                t++;
                pos = a[pos];
                if(k == t) {
                    System.out.println(pos + 1);
                    return;
                }
                if(v[pos]) {
                    long p = t - s[pos];
                    k -= t;
                    k %= p;
                    while(k > 0) {
                        pos = a[pos];
                        k--;
                    }
                    System.out.println(pos + 1);
                    return;
                } else {
                    s[pos] = t;
                    v[pos] = true;
                }
            }

    }



}
