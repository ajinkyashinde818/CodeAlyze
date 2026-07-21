import java.util.Scanner;

public class Main
{

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        String[][] a = new String[n][n];
        String[][] b = new String[m][m];
        for (int i = 0 ; i < n ; i++) {
            String c  = sc.next();
            for (int j = 0 ; j < n ; j++) {
                a[i][j] = c.substring(j, j + 1);
            }
        }

        for (int i = 0 ; i < m ; i++) {
            String c  = sc.next();
            for (int j = 0 ; j < m ; j++) {
                b[i][j] = c.substring(j, j + 1);
            }
        }

        boolean exist = false;
        for (int i = 0 ; i < n - m + 1 ; i++ ) {
            for (int j = 0 ; j < n - m + 1 ; j++ ) {
                boolean match = true;
                for (int k = 0 ; k < m ; k++ ) {
                    for (int l = 0 ; l < m ; l++ ) {
                        if (!a[k + i][l + j].equals(b[k][l])) {
                           match = false;
                        }
                    }
                }
                if (match) {
                    exist = true;
                }

            }
        }
        if (exist) {
            System.out.println("Yes");
        } else {
            System.out.println("No");
        }

    }

}
