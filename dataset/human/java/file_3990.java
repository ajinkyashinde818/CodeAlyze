import java.util.List;
import java.util.Scanner;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Set;
import java.util.Map;
import java.util.HashMap;
import javax.swing.text.DefaultStyledDocument.ElementSpec;

import java.util.HashSet;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int count = 0;
        int n = sc.nextInt();
        int[] a = new int[n];
        int[] b = new int[n];
        int[] c = new int[n - 1];
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
        }
        for (int i = 0; i < n; i++) {
            b[i] = sc.nextInt();
        }
        for (int i = 0; i < n - 1; i++) {
            c[i] = sc.nextInt();
        }
        for (int i = 0; i < n; i++) {

            count += b[a[i] - 1];

            if (i != 0 && a[i] == a[i - 1] + 1) {

                count += c[a[i - 1] - 1];
            }

        }
        System.out.println(count);
    }
}
