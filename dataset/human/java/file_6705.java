import java.util.*;
public class Main {
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        int K = sc.nextInt();
        int N = sc.nextInt();
        int[] A = new int[N];
        for(int i=0;i<N;i++){
            A[i] = sc.nextInt();
        }
        int sep = K-A[N-1] + A[0];
        for(int i=1;i<N;i++){
            sep = Math.max(sep, A[i]-A[i-1]);
        }
        System.out.println(K-sep);
    }

}
