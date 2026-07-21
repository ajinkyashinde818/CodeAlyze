import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int k = sc.nextInt();
        int n = sc.nextInt();
        int[] A = new int[n];
        Arrays.setAll(A, i -> Integer.parseInt(sc.next()));
        int ans = Integer.MAX_VALUE;
        for(int i = 0; i < n; i++)
            ans = Math.min(ans,
                    Math.min(i==0 ? A[n-1] - A[i] : k - (A[i] - A[i-1]),
                             i==n-1 ? A[i] - A[0] : A[i] + (k - A[i+1])));
        System.out.println(ans);
    }
}
