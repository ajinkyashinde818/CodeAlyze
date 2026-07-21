import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    static int[] w = new int[100010];
    static int[] v = new int[100010];
    static int[][] dp = new int[110][100010];
    static int k;

    static int chmin(int a, int b) {
        if (a > b) {
            a = b;
            return a;
        }
        return a;
    }

    static int chmax(int a, int b) {
        if (a < b) {
            a = b;
            return a;
        }
        return a;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        boolean aF = false;
        boolean bF = false;
        boolean cF = false;
        char[] s = sc.next().toCharArray();
        for (int i = 0; i < 3; i++) {
            if (s[i] == 'a')
                aF = true;
            else if (s[i] == 'b')
                bF = true;
            else if (s[i] == 'c')
                cF = true;

        }
        if (aF && bF && cF) {
            System.out.println("Yes");
            return;
        }
        System.out.println("No");

    }
}
