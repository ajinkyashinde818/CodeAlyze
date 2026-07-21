import java.util.*;

public class Main {
    public static void main(String args[]) {
        Scanner s = new Scanner(System.in);
        
        int N = s.nextInt();
        long[] A = new long[N];
        
        long sum = 0;
        int count = 0;
        
        for (int i = 0; i < N; i++) {
            A[i] = s.nextLong();
            if (A[i] < 0)
                count++;
            A[i] = Math.abs(A[i]);
            sum += A[i];
        }
        if (count % 2 == 1) {
            Arrays.sort(A);
            sum -= 2 * A[0];
        }
        System.out.print(sum);
    }

}
