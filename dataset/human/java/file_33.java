import java.util.*;
import java.util.stream.IntStream;

public class Main {
    static int n;
    static int[][] a = new int[2000][2000];


    static Scanner sc;

    public static void main(String[] args) {
        sc = new Scanner(System.in);
        n = sc.nextInt();

        if(n==1) {
            System.out.println("Yes");
            System.out.println("2");
            System.out.println("1 1");
            System.out.println("1 1");
            return;
        }

        if(n<3) {
            System.out.println("No");
            return;
        }
        int tmp = 4;
        a[0][0] = 1;
        a[0][1] = 2;
        a[1][0] = 2;
        a[1][1] = 3;
        a[2][0] = 3;
        a[2][1] = 1;
        if(n == 3) {
             out();
             return;
        }
        for (int i = 0; i < 1000; i++) {
            int j = 0;
            int l = 0;
            for (int k = 0; k < a[j].length; k++) {
                if (a[j][k] == 0) {

                    l = k;
                    break;
                }
            }
            while(a[j][0] != 0) {
                a[j][l] = tmp;
                tmp++;
                j++;
            }
            for (int k = 0; k <= l; k++) {
                a[j][k] = a[k][l];
            }
            if(tmp == n+1) {
                break;
            }
            if(tmp > n+1) {
                System.out.println("No");
                return;
            }
        }

        out();
    }

    static void out() {
        int l = 0;
        System.out.println("Yes");
        for (int i = 0; i < a[0].length; i++) {
            if(a[0][i] == 0 ){
                l = i;
                break;
            }
        }
        int ttt =0 ;
        for (int i = 0; i < a.length; i++) {
            if(a[i][0] == 0) {
                ttt = i;
                break;
            }
        }
        System.out.println(ttt);
        for (int i = 0; i < a.length; i++) {
            if(a[i][0] == 0) {
                return;
            }
            System.out.print(l + " ");
            for (int j = 0; j < l; j++) {
                System.out.print(a[i][j] + " ");
            }
            System.out.println();
        }
    }
}
