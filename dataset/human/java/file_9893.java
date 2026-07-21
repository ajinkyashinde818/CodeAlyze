import java.util.Scanner;

public class Main {
    private static int m = 0;
    private static int x = 0;

    public static void main(String args[]) {
        Scanner scan = new Scanner(System.in);

        int n = scan.nextInt();
        m = scan.nextInt();
        x = scan.nextInt();

        int[][] c = new int[n][m + 1];
        for (int row = 0; row < n; row++) {
            for (int line = 0; line <= m; line++) {
                c[row][line] = scan.nextInt();
            }
        }

        int minPrice = -1;
        for (int all = 1; all < Math.pow(2, n); all++) {
            int price = 0;
            String binary = Integer.toBinaryString(all);
            int[] level = new int[m];

            for (int row = 0, choice = binary.length(); 0 < choice; choice--, row++) {
                String judge = binary.substring(choice - 1, choice);

                if (judge.equals("1")) {
                    price += c[row][0];
                    for (int line = 0; line < m; line++) {
                        level[line] += c[row][line + 1];
                    }
                }
            }

            if (achieve(level)) {
                if (minPrice > price || minPrice == -1) {
                    minPrice = price;
                }
            }
        }

        System.out.println(minPrice);
    }

    private static boolean achieve(int[] level) {
        for (int a = 0; a < m; a++) {
            if (level[a] < x) {
                return false;
            }
        }
        return true;
    }
}
