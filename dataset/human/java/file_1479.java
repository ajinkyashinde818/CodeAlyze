import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();

        char[][] a = new char[n][n];
        for (int i = 0; i < n; i++) {
            a[i] = sc.next().toCharArray();
        }
        char[][] b = new char[m][m];
        for (int i = 0; i < m; i++) {
            b[i] = sc.next().toCharArray();
        }
        
        for (int i = 0; i < n - m + 1; i++) {
            for (int j = 0; j < n - m + 1; j++) {
                if (compare(a, b, i, j, m)) {
                    System.out.println("Yes");
                    return;
                }
            }
        }
        System.out.println("No");
    }

    static boolean compare(char[][] a, char[][] b, int i, int j, int m) {
        for (int k = 0; k < m; k++) {
            for (int l = 0; l < m; l++) {
                if (a[i + k][j + l] != b[k][l]) {
                    return false;
                }
            }
        }
        return true;
    }
}
