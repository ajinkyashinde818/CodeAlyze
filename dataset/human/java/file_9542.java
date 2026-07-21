/*
    Written by Kabir Kanha Arora
    @kabirkanha
 */

import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] a = new int[n];
        int[] b = new int[n];
        for (int i = 0; i < n; ++i) {
            a[i] = scanner.nextInt();
            b[i] = scanner.nextInt();
        }
        int cnt = 0;
        boolean flag = false;
        for (int i = 0; i < n; ++i) {
            if (a[i] != b[i])
                cnt = 0;
            else {
                cnt++;
                if (cnt == 3) {
                    flag = true;
                    break;
                }
            }
        }
        if (flag)
            System.out.println("Yes");
        else
            System.out.println("No");
    }

}
