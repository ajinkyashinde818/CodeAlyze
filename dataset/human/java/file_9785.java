import java.util.Scanner;

/**
 * Skill Up.
 */
public class Main {
    public static void main(String[] args) {
        var scanner = new Scanner(System.in);
        var n = scanner.nextInt();
        var m = scanner.nextInt();
        var x = scanner.nextInt();

        // load input data
        var costs = new int[n];
        var a = new int[n][m];
        for (int i = 0; i < n; i++) {
            costs[i] = scanner.nextInt();
            for (int j = 0; j < m; j++) {
                a[i][j] = scanner.nextInt();
            }
        }
        // process
        var totalCost = Integer.MAX_VALUE;
        var found = false;
        for (int i = 0; i < Math.pow(2, n); i++) {
            var c = 0;
            var level = new int[m];
            var achieved = true;
            for (int j = 0; j < n; j++) {
                if ((1 & i >> j) == 1) {
                    c += costs[j];
                    for (int k = 0; k < m; k++) {
                        level[k] += a[j][k];
                    }
                }
            }
            for (int l : level) {
                if (l < x) {
                    achieved = false;
                    break;
                }
            }
            if (achieved) {
                totalCost = Math.min(totalCost, c);
                found = true;
            }
        }
        System.out.println(found ? totalCost : -1);
    }
}
