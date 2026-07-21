import java.io.InputStream;
import java.io.PrintStream;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) throws Exception {
        solve(System.in, System.out);
    }

    static void solve(InputStream is, PrintStream os) {
        // Your code here!
        Scanner sc = new Scanner(is);
        int N = sc.nextInt();
        int A[] = new int[N];
        int B[] = new int[N];

        for (int i = 0; i < N; i++) {
            A[i] = sc.nextInt();
        }
        for (int i = 0; i < N; i++) {
            B[i] = sc.nextInt();
        }

        if(N ==1) {
            os.println("No");
            return;
        }

        int secondP = 1;

        for (int i = 0; i < N; i++) {
            if(0 < i && A[i] != A[i-1])
                secondP = 0;
            if(A[i] == B[i]){
                while(secondP < N) {
                    if(A[i] != B[secondP] && A[secondP] != B[i]) {
                        int tmp = B[i];
                        B[i] = B[secondP];
                        B[secondP] = tmp;
                        break;
                    }
                    secondP++;

                }
                if(A[i] == B[i]) {
                    os.println("No");
                    return;
                }
            }
        }
        os.println("Yes");
        for (int i = 0; i < N; i++) {
            os.print(B[i]);
            if(i < N-1)
                os.print(" ");
        }
        os.println();
    }

}
