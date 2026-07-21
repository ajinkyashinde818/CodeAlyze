import java.util.*;
import java.math.*;

public class Main {
    public static void main(String[] args) {
        Scanner itr = new Scanner(System.in);
        int K = itr.nextInt();
        int N = itr.nextInt();
        int[] place = new int[N];

        for (int i = 0; i < N; i++) {
            place[i] = itr.nextInt();
        }
        Arrays.sort(place);
        int max = K - place[N - 1] + place[0];
        for (int i = 1; i < N; i++) {
            max = Math.max(max, place[i] - place[i - 1]);
        }

        System.out.println(K - max);
    }
}
