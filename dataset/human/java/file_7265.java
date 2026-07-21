import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        int K = sc.nextInt();
        int N = sc.nextInt();
        int[] arr = new int[N];
        int[] dist = new int[N];
        int result = 0;
        

        for(int i = 0; i < N; i++) {
            arr[i] = sc.nextInt();
        }

        int first = K - arr[N-1] + arr[0];
        dist[0] = first;

        for(int j = 1; j < N; j++) {
            dist[j] = arr[j] - arr[j-1];
        }
        Arrays.sort(dist);

        for(int k = 0; k < N-1; k++) {
            result += dist[k];
        }
        System.out.println(result);
    }
}
