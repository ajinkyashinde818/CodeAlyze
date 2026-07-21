import java.util.Scanner;

/**
 * Main
 */
public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int K = sc.nextInt();
        int N = sc.nextInt();
        int[] A = new int[N+1];
        int maxLength = 0;

        for(int i = 1; i <= N; i++){
            A[i] = sc.nextInt();
            // if(i != 1){
                if(maxLength < A[i]-A[i-1]){
                    maxLength =  A[i]-A[i-1];
                }
            // }
        }
        if(maxLength < A[1]+K-A[N]){
            maxLength =  A[1]+K-A[N];
        }

        System.out.println(K-maxLength);    
    }
}
