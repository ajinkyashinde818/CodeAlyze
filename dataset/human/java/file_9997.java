import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int m = scanner.nextInt();
        int x = scanner.nextInt();
        int[] costs = new int[n];
        int[][] values = new int[n][m];

        for (int i = 0; i < n; i++) {
            costs[i] = scanner.nextInt();
            for (int j = 0; j < m; j++) {
                values[i][j] = scanner.nextInt();
            }
        }

        int result = select(costs, values, x, new int[m], 0, 0);
        System.out.println(result == Integer.MAX_VALUE ? -1 : result);
    }

    private static int select(int[] costs, int[][] values, int x,
                       int[] learned, int current, int prevCost) {
        boolean successful = true;
        for (int value : learned) {
            if (value < x) {
                successful = false;
                break;
            }
        }
        if (successful) return prevCost;
        if (current >= costs.length) return Integer.MAX_VALUE;

        int notSelectCost = select(costs, values, x, learned, current + 1, prevCost);

        int[] newLearned = new int[learned.length];
        for (int i = 0; i < learned.length; i++) {
            newLearned[i] = learned[i] + values[current][i];
        }
        int selectCost = select(costs, values, x, newLearned, current + 1, prevCost + costs[current]);

        return Math.min(notSelectCost, selectCost);
    }
}
