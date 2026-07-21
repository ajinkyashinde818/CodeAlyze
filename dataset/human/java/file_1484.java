import java.util.Scanner;
import java.util.HashMap;
import java.util.List;
import java.util.Arrays;
import java.util.ArrayList;
import java.lang.Math;

public class Main {

    static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        int n = sc.nextInt();
        int m = sc.nextInt();
        String[] a = new String[n];
        String[] b = new String[m];
        for (int i = 0; i < n; i++) {
            a[i] = sc.next();
        }
        for (int i = 0; i < m; i++) {
            b[i] = sc.next();
        }
        for (int i = 0; i <= n - m; i++) {
            for (int j = 0; j <= n - m; j++) {
                boolean flag = true;
                for (int k = 0; k < m; k++) {
                    for (int l = 0; l < m; l++) {
                        if (a[i+k].charAt(j+l) != b[k].charAt(l)) {
                            flag = false;
                        }
                    }
                }
                if (flag) {
                    System.out.println("Yes");
                    System.exit(0);
                }
            }
        }
        System.out.println("No");
    }

}
