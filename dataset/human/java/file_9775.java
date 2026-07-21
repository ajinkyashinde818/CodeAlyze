import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = nextInt(scanner);
        int m = nextInt(scanner);
        int x = nextInt(scanner);
        int[] c = new int[n];
        int[][] a = new int[n][m];
        for (int i = 0; i < n; i++) {
            c[i] = nextInt(scanner);
            for (int j = 0; j < m; j++) {
                a[i][j] = nextInt(scanner);
            }
        }

        int finalPrice = -1;
        for (int i = 0; i < Math.pow(2, n); i++) {
            int[] points = new int[m];
            int price = 0;
            for (int j = 0; j < n; j++) {
                if ((1 & i >> j) == 1) {
                    for (int k = 0; k < m; k++) {
                        points[k] += a[j][k];
                    }
                    price += c[j];
                }
            }
            boolean isPass = true;
            for (int point: points) {
                if (point < x) {
                    isPass = false;
                    break;
                }
            }
            if (isPass) {
                if (finalPrice > price || finalPrice == -1) {
                    finalPrice = price;
                }
            }
        }
        System.out.println(finalPrice);
    }

    public static int nextInt(Scanner scanner) {
        return Integer.parseInt(scanner.next());
    }
}
