import java.io.PrintWriter;
import java.util.*;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = Integer.parseInt(sc.next());
        int A[] = new int[N];
        for (int i=0; i<N; i++)
            A[i] = Integer.parseInt(sc.next());
        int B[] = new int[N];
        for (int i=0; i<N; i++)
            B[i] = Integer.parseInt(sc.next());
        int C[] = new int[N-1];
        for (int i=0; i<N-1; i++)
            C[i] = Integer.parseInt(sc.next());
        sc.close();

        int sum = Arrays.stream(B).sum();

        for (int i=0; i<N-1; i++) {
            if (A[i]+1==A[i+1])
                sum += C[A[i]-1];
        }

        PrintWriter out = new PrintWriter(System.out);
        out.println(sum);
        out.flush();
    }
}
