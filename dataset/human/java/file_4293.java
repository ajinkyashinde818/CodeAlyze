import java.util.*;

public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int A[] = new int[N];
        int B[] = new int[N];
        int C[] = new int[N];
        for(int i = 0; i < N; i++){
            A[i] = sc.nextInt();
        }
        for(int i = 0; i < N; i++){
            B[i] = sc.nextInt();
        }
        for(int i = 0; i < N - 1; i++){
            C[i] = sc.nextInt();
        }
        int result = 0;
        int prev = N + 1;
        for(int i = 0; i < N; i++){
            result += B[A[i] - 1];
            if(prev + 1 ==  A[i]){
                result += C[A[i - 1] - 1];
            }
            prev = A[i];
        }
        System.out.println(result);
    }
}
