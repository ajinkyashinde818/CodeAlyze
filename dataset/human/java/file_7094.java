import java.util.*;
import java.math.*;

class Main{
	public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int K = sc.nextInt();
        int N = sc.nextInt();
        int[] A = new int[N];
        for(int i = 0; i < N; i++){
            A[i] = sc.nextInt();
        }
        int max = A[0] - A[N - 1] + K;
        for(int i = 0; i < N - 1; i++){
            if(max < A[i + 1] - A[i]){
                max = A[i + 1] - A[i];
            }
        }
        System.out.print(K - max);
	}

}
