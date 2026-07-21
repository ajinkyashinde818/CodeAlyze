import java.util.*;

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

        for (int startY = 0; startY <= n - m; startY++) {
            for (int startX = 0; startX <= n - m; startX++) {
                boolean hasMatch = true;

                loop : for (int i = 0; i < m; i++) {
                    for (int j = 0; j < m; j++) {
                        if (a[startY + i][startX+j] != b[i][j]) {
                            hasMatch = false;
                            break loop;
                        }
                    }
                }

                if (hasMatch) {
                    System.out.println("Yes");
                    return;
                }
            }
        }
        System.out.println("No");

    }
}
