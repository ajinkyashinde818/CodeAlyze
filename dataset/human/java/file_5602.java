//package unk;

import java.util.Scanner;

/**
 * @author sguar <shugangcao@gmail.com>
 * welcome to kuaishou
 * Created on 2020-01-10
 */
public class Main {

    private int a1 = 1;
    private int a2 = 1_000_000_000;
    public void run() {
        Scanner cin = new Scanner(System.in);
        int n = cin.nextInt();
        int k = cin.nextInt();
        int S = cin.nextInt();
        int unUsed = a2;
        if (S == a2) {
            unUsed = a1;
        }
        for (int i = 1; i <= k; i++) {
            System.out.print(S);
            if (i < k) System.out.print(" ");
        }
        if (k < n) {
            for (int i = k + 1; i <= n; i++) {
                System.out.print(" " + unUsed);
            }
        }
    }
    public static void main(String[] args) {
        new Main().run();
    }
}
