import java.util.*;
import java.math.*;
import java.io.*;
import java.lang.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        char[][] a = new char[n][n];
        char[][] b = new char[m][m];
        String s;
        for (int i = 0; i < n; i++) {
            s = sc.next();
            for (int j = 0; j < n; j++) {
                a[i][j] = s.charAt(j);
            }
        }


        for (int i = 0; i < m; i++) {
            s = sc.next();
            for (int j = 0; j < m; j++) {
                b[i][j] = s.charAt(j);
            }
        }
        for (int i = 0; i <= n-m; i++) {
            for (int j = 0; j <= n-m; j++) {
                boolean f = true;
                for (int k = 0; k < m; k++) {
                    for (int l = 0; l < m; l++) {
                        if(b[k][l] != a[i+k][j+l]){
                            f = false;
                        }
                    }
                }
                if(f){
                    io.YesNo(true);
                    return;
                }
            }
        }
        io.YesNo(false);

    }
}

class io{
    public static void br(){
        System.out.println("");
    }

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
