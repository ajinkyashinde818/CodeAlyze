import java.io.StreamCorruptedException;
import java.util.*;
import static java.lang.System.*;
import static java.lang.Math.*;

public class Main {
    static long pow10(int n){
        long a = 1;
        for(int i=0;i<n;i++) a*=10;
        return a;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(in);
        int n, k, A, r, K;
        while(true){
            n = sc.nextInt();
            k = sc.nextInt();
            if(n == 0 && k == 0) break;

            A = 0; K = 1;
            for(int i=1;;i++){
                long p = 9 * pow10(i-1) * i;
                if((long)n - (A+p) < 0) break;
                A += (int)p;
                K = i+1;
            }
            r = n - A;

//            out.println("n="+n+" ,A="+A+" ,r="+r +" ,K="+K);
            int v = (int)pow10(K-1) + r / K;
            int vi = r % K;

//            out.println(v+","+vi);
            StringBuilder sb = new StringBuilder();
            int ii = v;
            while(sb.length() <= 2*k){
                sb.append(ii++);
            }
            if(vi > 0){
//                out.println(sb);
                out.println(sb.substring(vi-1, vi-1+k));
            }
            else{
                String vv = (v-1)+"";
                sb.insert(0, vv.charAt(vv.length()-1));
                out.println(sb.substring(0, k));
            }
        }
    }

}
