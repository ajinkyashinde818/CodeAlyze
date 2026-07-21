import java.util.*;

public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        final int N = sc.nextInt();
        int M = sc.nextInt();
        int[] A = new int[N+1];
        int[] B = new int[N+1];
        for(int i = 0;i < M;i++){
            int a = sc.nextInt();
            int b = sc.nextInt();
            if(a == 1)  A[b]++;
            else if(b == N) B[a]++;
        }
        for(int i = 0;i < N+1;i++){
            if(A[i]+B[i] == 2){
                System.out.println("POSSIBLE");
                return;
            }
            if(i == N)  System.out.println("IMPOSSIBLE");
        }
    }
}
