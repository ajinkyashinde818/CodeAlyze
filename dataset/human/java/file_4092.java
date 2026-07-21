import java.util.Scanner;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] a = new int[n];
        int[] b = new int[n];
        int[] c = new int[n - 1];
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt() - 1;
        }
        for (int i = 0; i < n; i++) {
            b[i] = sc.nextInt();
        }
        for (int i = 0; i < n - 1; i++) {
            c[i] = sc.nextInt();
        }
        int levelOfSaticfaction_b = 0;
        int levelOfSaticfaction_c = 0;
        for (int i = 0; i < a.length; i++) {
            levelOfSaticfaction_b += b[a[i]];
            if (i >= 1) {
                if (a[i] - a[i - 1] == 1) {
                    levelOfSaticfaction_c += c[a[i - 1]];
                }
            }
        }
        System.out.println(levelOfSaticfaction_b + levelOfSaticfaction_c);
        sc.close();
    }
}
