import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int K = sc.nextInt();
        int N = sc.nextInt();
        int lastPoints = 0;
        int firstDistance = 0;
        int[] distanceArray = new int[N];
        for (int i = 0; i < N; i++) {
            int point = sc.nextInt();
            int distance = 0;
            if (i == 0) {
                lastPoints = point;
                firstDistance = point;
                continue;
            }
            distance = point - lastPoints;
            if (i == N - 1) {
                int lastDistance = K - point + firstDistance;
                distanceArray[i] = lastDistance;
            }
            distanceArray[i - 1] = distance;
            lastPoints = point;
        }
        sc.close();
        Arrays.sort(distanceArray);
        int minDistance = 0;
        for (int i = 0; i < N - 1; i++) {
            minDistance += distanceArray[i];
        }

        System.out.println(minDistance);
    }
}
