import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] A = new int[n];
        long sum = 0;
        long res = Long.MAX_VALUE;
        for(int i = 0; i < n; i++) {
            A[i] = Integer.parseInt(sc.next());
            sum += A[i];
        }
        long tmp = 0;
        for(int i = 0; i < n-1; i++) {
            tmp += A[i];
            res = Math.min(res, Math.abs(2 * tmp - sum));
        }
        System.out.println(res);
    }
}
