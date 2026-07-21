import java.util.*;
import java.math.*;
import java.io.*;
import java.lang.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int res = 0;
        int[] a = new int[n];
        int[] b = new int[n];
        int[] c = new int[n-1];
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
        }
        for (int i = 0; i < n; i++) {
            b[i] = sc.nextInt();
            res += b[i];
        }
        for (int i = 0; i < n-1; i++) {
            c[i] = sc.nextInt();
        }
        for (int i = 1; i < n; i++) {
            if(a[i]-a[i-1] == 1){
                res+=c[a[i-1]-1];
            }
        }
        System.out.println(res);
    }
}

class io{

    public static void YesNo(boolean f) {
        System.out.println(f?"Yes":"No");
    }
    public static void YESNO(boolean f) {
        System.out.println(f?"YES":"NO");
    }
}

class Algo{
    public static boolean isOdd(int n){
        return n % 2 == 1;
    }
    public static boolean isEven(int n){
        return n % 2 == 0;
    }


}
