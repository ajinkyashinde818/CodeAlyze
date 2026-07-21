import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        int nmap[][] = new int[n][n];
        for (int i = 0; i < n; i++) {
            String s = sc.next();
            for (int j = 0; j < n; j++) {
                if (s.charAt(j) == '#') {
                    nmap[i][j] = 1;
                } else {
                    nmap[i][j] = 0;
                }
            }
        }
        int mmap[][] = new int[m][m];
        for (int i = 0; i < m; i++) {
            String s = sc.next();
            for (int j = 0; j < m; j++) {
                if (s.charAt(j) == '#') {
                    mmap[i][j] = 1;
                } else {
                    mmap[i][j] = 0;
                }
            }
        }
        sc.close();
        for (int i = 0; i < n - m + 1; i++) {
            aa: for (int j = 0; j < n - m + 1; j++) {
                // i , j は左上の座標
                if (nmap[i][j] != mmap[0][0]) {
                    continue;
                } else {
                    for (int k = 0; k < m; k++) {
                        for (int l = 0; l < m; l++) {
                            if (nmap[i + k][j + l] != mmap[k][l]) {
                                continue aa;
                            }
                        }
                    }
                    System.out.println(("Yes"));
                    return;
                }
            }
        }
        System.out.println(("No"));

    }
}
