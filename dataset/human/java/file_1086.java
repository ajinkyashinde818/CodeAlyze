//package src.com.jetman.atcoder;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

/**
 * @description:
 * @author: Jetman
 * @create: 2020-08-29 14:39
 **/
public class Main {

    Scanner sc = new Scanner(System.in);

    long MOD = 1000000000 + 7;


    private void slove() {

        int n = sc.nextInt();

        int[] a = new int[n];
        int[] b = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
        }
        for (int i = 0; i < n; i++) {
            b[n-i-1] = sc.nextInt();
        }

        int c = -1;
        for (int i = 0; i < n; i++) {
            if (a[i] == b[i]) {
                c = a[i];
                break;
            }
        }
        int l = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] == c && b[i] == c) {
                l = i;
                break;
            }
        }
        int r = -1;
        for (int i = n-1; i >=0; i--) {
            if (a[i] == c && b[i] == c) {
                r = i;
                break;
            }
        }

        for (int i = 0; i < n; i++) {
            if (c != -1 && a[i] != c && b[i] != c && l <= r) {
                int tmp = b[i];
                b[i] = b[l];
                b[l] = tmp;
                l++;
            }
        }
        if (l <= r) {
            System.out.println("No");
        } else {
            System.out.println("Yes");
            for (int i = 0; i < n; i++) {
                System.out.print(b[i] + " ");
            }
        }








    }

    public static void main(String[] args) {
        new Main().slove();
    }
}
