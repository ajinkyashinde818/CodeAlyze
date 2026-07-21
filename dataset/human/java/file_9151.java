import java.util.*;

public class Main{
    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
        int n = scan.nextInt();
        int m = scan.nextInt();
        boolean[] a = new boolean[n];
        long[] g = new long[n];

        for (int k=0;k<n;k++){
            a[k] = false;
            g[k] = 0;
        }

        for (int i=0;i<m;i++){
            int t = scan.nextInt();
            a[t-1] = true;
        }

        if (n == 1){
            if (m == 1){
                System.out.println(0);
            }
            else{
                System.out.println(1);
            }
            return;
        }
        long sum = 0;
        g[0] = 1;
        g[1] = 1;
        if (a[0] == true){
            g[1] = 0;
        }
        sum = find(2, n, a, g);
        long q = 1000000007;
        System.out.println((long) sum % q);
    }

    static long find(int current, int n, boolean[] a, long[] g){
        
        if (current == n){
            return g[n-1]+g[n-2];
        }
        
        if (a[current-1] == true){
            g[current] = 0;
        }
        else{
            g[current] = g[current-1] + g[current-2];
        }
        long q = 1000000007;
        g[current] = (long) g[current] % q;
        return (long) find(current + 1, n, a, g);
    }
}
