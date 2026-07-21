import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        int K = sc.nextInt();
        int N = sc.nextInt();
        
        int[] A =new int[N];
        
        for(int i=0;i<N;i++){
            A[i]=sc.nextInt();
        }
        long max =A[0]+(K-A[N-1]);
        
        for(int i=0;i<N-1;i++){
            max = Math.max(max, A[i+1]-A[i]);
        }
        System.out.println(K-max);
        
    }
}
