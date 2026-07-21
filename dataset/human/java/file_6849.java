import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int K = scanner.nextInt();
        int N = scanner.nextInt();

        int[] A = new int[N + 1];

        int longestDist = 0;
        int totalDist = 0;
        for (int i = 1 ; i <= N ; i++) {
            A[i] = scanner.nextInt();
            if (i != 1) {
                int dist = A[i] - A[i - 1];
                totalDist += dist;
                longestDist = Math.max(longestDist, dist);
            }
        }

        int dist = K - A[N] + A[1];
        totalDist += dist;
        longestDist = Math.max(longestDist, dist);
        System.out.println(totalDist - longestDist);
    }
}
