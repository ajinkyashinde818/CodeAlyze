import java.util.*;

public class Main {

    public static void main(String[] args) {
        exec();
    }

    static void exec() {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] A = new int[n];
        int[] B = new int[n];
        int[] C = new int[n-1];

        for (int i = 0; i < n; i++) {
            A[i] = sc.nextInt();
        }
        for (int i = 0; i < n; i++) {
            B[i] = sc.nextInt();
        }
        for (int i = 0; i < n-1; i++) {
            C[i] = sc.nextInt();
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans += B[i];
            if(i > 0 && A[i]- A[i-1] == 1) {
                ans += C[A[i-1]-1];
            }
        }

        System.out.println(ans);
   }
}
