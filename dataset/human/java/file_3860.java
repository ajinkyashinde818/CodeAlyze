/*
* @Author Silviase(@silviasetitech)
* For ProCon
*/

import java.util.*;
import java.lang.*;
import java.math.*;

public class Main{

        static int MOD = (int)1e9+7;

        // for dfs
        static int n;
        static int ansi;
        static int[] w;
        static int[] ww;
        static boolean[] isvisited;
        //
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);

        int ans = 0;
        String s = sc.next();

        sc.close();

        StringBuffer sb = new StringBuffer(s);
        while(true){
            if (sb.length() <= 1) {
                System.out.println(ans);
                return;
            }else{
                if (sb.charAt(0) == sb.charAt(sb.length()-1) ) {
                    sb.deleteCharAt(0);
                    sb.deleteCharAt(sb.length()-1);
                }else{
                    if (sb.charAt(0) == 'x') {
                        sb.append("x");
                        ans++;
                    }else if (sb.charAt(sb.length()-1) == 'x') {
                        sb.insert(0,"x");
                        ans++;
                    }else{
                        System.out.println(-1);
                        return;
                    }
                }
            }
        }
    }

    


    /*
    For Numeric Analysis
    */
    public static int ManhattanDist(int x, int y, int xx, int yy) {
        return(Math.abs(xx-x) + Math.abs(yy-y));
    }

    public static double FuncOfx(double x, int funcnum) {
        switch (funcnum) {
            case 1:
                return x*x;

            case 2:
                return Math.exp(-1*x)-x*x;
        
            default:
                throw new IllegalArgumentException("Such Func doesn't Exist.");
        }
            
    }

    public static void Nibutan(double target, int funcnum) {
        int callcounter = 0;
        double lowbound = Integer.MIN_VALUE;
        double highbound = Integer.MAX_VALUE;
        double pivot = (lowbound + highbound)/2;
        double tmp;
        double tmp4swap;
        if (funcnum == 1) {
            lowbound = 0;
            pivot = (lowbound+highbound)/2;
        }
        while (true) {
            callcounter++;
            if (FuncOfx(highbound, funcnum) < FuncOfx(lowbound, funcnum)) {
                tmp4swap = highbound;
                highbound = lowbound;
                lowbound = tmp4swap;
            }

            if (FuncOfx(pivot,funcnum) > target) {
                System.out.println(String.format("%2d", callcounter) + ": " 
                            + String.format("%.6f", pivot) + " f(" + String.format("%.6f", pivot) +") is " 
                            + String.format("%.6f",FuncOfx(pivot,funcnum))  + ", so too high :(");
                tmp = (lowbound + pivot)/2;
                if ( Math.abs(tmp-pivot) < 0.00005 ) {
                    System.out.println("Found!" +String.format("%.3f", tmp)+" is the answer.");
                    return;
                }
                highbound = pivot;
                pivot = tmp;
            }else if(FuncOfx(pivot,funcnum) < target){
                System.out.println(String.format("%2d", callcounter) + ": " 
                            + String.format("%.6f", pivot) + " f(" + String.format("%.6f", pivot) +") is " 
                            + String.format("%.6f",FuncOfx(pivot,funcnum))  + ", so too high :(");
                tmp = (highbound + pivot)/2;
                if ( Math.abs(tmp-pivot) < 0.00005 ) {
                    System.out.println("Found!" +String.format("%.3f", tmp)+" is the answer.");
                    return;
                }
                lowbound = pivot;
                pivot = tmp;
            }
        }
        
    }

    /*
    Numeric Analysis End
    */

    private static long[][] CombinationLong_nCk(long n, long k) {
        n++; k++;
        long[][] ans = new long[(int)n][(int)k];
        for (int i = 0; i < n; i++) {
            ans[i][0] = 1;
        }
        for (int i = 0; i < n-1; i++) {
            for (int j = 0; j < k-1; j++) {
                if (i < j) {
                    ans[i][j] = 0;
                }else{
                    ans[i+1][j+1] = ans[i][j] + ans[i][j+1];
                }
            }
        }
        return ans;
    }

        public static int gcd_int(int a, int b) {
        
            if (a < b) {
                int tmpp = a;
                a = b;
                b = tmpp;
            }
            if (b == 0) {
                return a;
            }else{
                return gcd_int(b, a%b);
            }
        } 

        public static long gcd_long(long a, long b) {
        
            if (a < b) {
                long tmpp = a;
                a = b;
                b = tmpp;
            }
            if (b == 0) {
                return a;
            }else{
                return gcd_long(b, a%b);
            }
        }

        public static int lcm_int(int a, int b) {
            int gcd = gcd_int(a,b);
            return a/gcd*b;
        }

        public static long lcm_long(long a, long b) {
            long gcd = gcd_long(a,b);
            return a/gcd*b;
        }

        public static void dfs(int placenow) {
            // if went all -> success! 
            // if not went all -> fail...
            
            /*
            dfs    
            Go All Place that there is way to and not having been yet. 

             if island 1 is start point, dfs(1);
            if there is way to island 2 and island 3,
            - island 2 changes non-visited -> visited, and dfs(2).
            - island 3 changes non-visited -> visited, and dfs(3).
    
            */

            isvisited[placenow] = true;
            boolean success = true;
            for (int i = 0; i < n; i++) {
                if (isvisited[i] == false) { // not go all place
                    success = false;
                    break;
                }
            }
            if (success) {
                ansi++;
                isvisited[placenow] = false;
                return;
            }

            for (int i = 0; i < n; i++) {
                if (w[i] == placenow && isvisited[ww[i]] == false ) {
                    dfs(ww[i]);
                }else if(ww[i] == placenow && isvisited[w[i]] == false){
                    dfs(w[i]);
                }else{
                    continue;
                }
            }
            isvisited[placenow] = false;
            return;
        }

}
