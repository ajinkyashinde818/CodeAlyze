import java.util.*;
import java.io.*;
import java.lang.*;
import java.math.*;
public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));
        int n = Integer.parseInt(bf.readLine());
        int[] a = new int[2*n];
        String s = bf.readLine();
        for(int i=0; i<2*n; i++) a[i] = (s.charAt(i)=='B')?1:0;
        for(int i=1; i<2*n; i+=2) a[i] = 1-a[i];
        int count = 0;
        int mod = 1000000007;
        long ans = 1;
        for(int i=0; i<2*n; i++) {
          if(a[i] == 1) count++;
          else {
            ans *= count;
            count--;
            ans %= mod;
          }
        }
        for(int i=1; i<=n; i++) {
          ans *= i;
          ans %= mod;
        }
        if(count != 0) out.println(0);
        else out.println(ans);
        // StringTokenizer st = new StringTokenizer(bf.readLine());
        // int[] a = new int[n]; for(int i=0; i<n; i++) a[i] = Integer.parseInt(st.nextToken());
        // int n = Integer.parseInt(st.nextToken());

        out.close(); System.exit(0);
    }
}
