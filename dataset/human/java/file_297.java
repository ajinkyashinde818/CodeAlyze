import java.util.Arrays;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        // write your code here
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        long A[] = new long[N];
        int min = 0;
        int count = 0;
        long sum = 0;
        Arrays.setAll(A, i -> scanner.nextInt());

        for (int i = 0; i < N; i ++) {
            if (Math.abs(A[min]) > Math.abs(A[i])) min = i;
            if (A[i] < 0) count ++;
            sum += Math.abs(A[i]);
        }

        if (count % 2 != 0) sum -= Math.abs(A[min]) * 2;

        System.out.println(sum);
    }
}
