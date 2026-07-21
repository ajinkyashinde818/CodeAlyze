import java.io.InputStream;
import java.io.PrintStream;
import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        solve(System.in, System.out);
    }

    static void solve(InputStream is, PrintStream os) {
        // Your code here!
        Scanner scan = new Scanner(is);
        int N = scan.nextInt();
        int A[] = new int[N];
        int B[] = new int[N];
        int C[] = new int[N-1];
        for(int i = 0; i < N ; i++) {
            A[i] = scan.nextInt() - 1;
        }
        for(int i = 0; i < N ; i++) {
            B[i] = scan.nextInt();
        }
        for(int i = 0; i < N-1 ; i++) {
            C[i] = scan.nextInt();
        }

        long answer = 0;
        answer += B[A[0]];
        for(int i = 1; i < N; i++) {
            answer += B[A[i]];
            if(A[i] == A[i-1] +1) {
                answer += C[A[i-1]];
            }
        }
        os.println(answer);


    }
}
