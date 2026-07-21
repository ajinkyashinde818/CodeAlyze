import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        Integer K = input.nextInt();
        Integer N = input.nextInt();
        Integer A[] = new Integer[N];
        Integer distances[] = new Integer[N];
        Integer sumDistance = 0;
        Integer maxDistance = 0;

        for (int i = 0; i < N; i++) {
            A[i] = input.nextInt();
        }
        Arrays.sort(A);

        for (int i = 0; i < N - 1; i++) {
            distances[i+1] = A[i+1] - A[i];
        }
        distances[0] = (K - A[N-1]) + A[0];

        for (Integer distance : distances) {
            sumDistance += distance;
            maxDistance = Math.max(maxDistance, distance);
        }

        System.out.println(sumDistance - maxDistance);
    }
}
