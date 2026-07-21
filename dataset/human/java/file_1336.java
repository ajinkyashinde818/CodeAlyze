import java.util.Scanner;

public class Main {

    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int m = sc.nextInt();

        char[][] a = new char[n][n];
        char[][] b = new char[m][m];

        for (int i = 0; i < n; i++) {
            a[i] = sc.next().toCharArray();
        }

        for (int i = 0; i < m; i++) {
            b[i] = sc.next().toCharArray();
        }

        boolean ans = false;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (j + m - 1 >= n || i + m - 1 >= n) {
                    continue;
                }
                boolean match = true;
                for (int y = 0; y < m; y++) {
                    for (int x = 0; x < m; x++) {
                        if (a[i + y][j + x] != b[y][x]) {
                            match = false;
                        }
                    }
                }
                if (match) {
                    ans = true;
                }
            }
        }

        sc.close();

        System.out.println(ans ? "Yes" : "No");
    }

}
