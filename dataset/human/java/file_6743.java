import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int K = sc.nextInt();
        int N = sc.nextInt();
        int[] A = new int[N];
        int maxDistance = 0;
        for(int i=0;i<N;i++){
            A[i] = sc.nextInt();
        }

        for(int i=0;i<N;i++){
            if(i < N-1){
                maxDistance = Math.max(maxDistance,A[i+1] - A[i]);
            } else {
                maxDistance = Math.max(maxDistance,A[0] + K - A[i]);
            }
        }

        System.out.println(K - maxDistance);

    }

}
