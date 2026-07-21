import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        // ABC158D - String Formation

        Scanner sc = new Scanner(System.in);

        String s = sc.next();

        int q = sc.nextInt();

        int[] t = new int[q];
        int[] f = new int[q];
        String [] c = new String[q];

        StringBuilder prefix = new StringBuilder();
        StringBuilder suffix = new StringBuilder();

        boolean isReverse = false;

        for (int i = 0; i < q; i++) {
            t[i] = sc.nextInt();
            if (t[i] == 2) {
                f[i] = sc.nextInt();
                c[i] = sc.next();
                if (!isReverse) {
                    if (f[i] == 1) {
                        prefix.insert(0, c[i]);
                    } else {
                        suffix.append(c[i]);
                    }
                } else {
                    if (f[i] == 2) {
                        prefix.insert(0, c[i]);
                    } else {
                        suffix.append(c[i]);
                    }
                }
            } else {
                isReverse = !isReverse;
            }
        }

        StringBuilder ans = new StringBuilder(prefix + s + suffix);

        if (isReverse) {
            ans = ans.reverse();
        }

        System.out.println(ans);
    }
}
