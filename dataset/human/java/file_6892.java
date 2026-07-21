import java.util.*;
public class Main {
    static final long MODVAL = 998244353L;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int K = sc.nextInt();
        int N = sc.nextInt();
        int A[] = new int[N+2];
        for(int i=0; i<N; i++) {
            A[i+1] = sc.nextInt();
        }
        A[0] = A[N] - K;
        A[N+1] = A[1] + K;
        int result = K;
        for(int i=0; i<N+1; i++) {
            if(K-(A[i+1]-A[i]) < result) {
               result = K-(A[i+1]-A[i]);
            }
        }
        System.out.println(result);
    }
}
