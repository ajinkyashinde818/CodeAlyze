import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int x = scanner.nextInt();
        int y = scanner.nextInt();
        int[] dist = new int[y];

        for (int i = 0; i < y; i++) {
            dist[i] = scanner.nextInt();
        }

        scanner.close();

        int[] sa = new int[y];

        for (int i = 0; i < dist.length; i++) {
            if (i == 0) {
                sa[0] = dist[0];
            } else {
                sa[i] = dist[i] - dist[i - 1];
            }
            if (i == dist.length - 1) {
                sa[0] += x - dist[i];
            }
        }

        dist = null;

        int max = sa[0];
        int sum = 0;
        for (int i : sa) {
            if (i > max) {
                max = i;
            }
            sum += i;
        }

        System.out.println(sum - max);
    }
}
