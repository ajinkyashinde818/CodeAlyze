import java.util.Scanner;

public class Main {
    public static void debug(String str) {
        System.out.println(str);
    }

    public static void main(String[] args) {

        int N;
        long[] A;
        long[] B;
        long[] C;

        try (Scanner sc = new Scanner(System.in)) {
            N = sc.nextInt();
            A = new long[N];
            B = new long[N];
            C = new long[N];
            for(int i = 0;i < N;i++){
                A[i] = sc.nextLong();
            }
            for(int i = 0;i < N;i++){
                B[i] = sc.nextLong();
            }
            for(int i = 0;i < N - 1;i++){
                C[i] = sc.nextLong();
            }
        }
        long result = 0;
        for(int i = 0;i < N - 1;i++){
            if(A[i] +1 == A[i+1]){
                result += C[(int)A[i]-1];
            }
        }
        for(int i = 0;i < N;i++){
            result += B[i];
        }
        System.out.println(result);
    }

}
