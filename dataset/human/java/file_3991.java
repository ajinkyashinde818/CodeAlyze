import java.util.*;

public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);

        int N = sc.nextInt();
        int[] A = new int[N];
        int[] B = new int[N];
        int[] C = new int[N-1];
        int bsum = 0;
        int csum = 0;

        for(int i=0; i<=N-1; i++){
            A[i] = sc.nextInt();
        }
        for(int i=0; i<=N-1; i++){
            B[i] = sc.nextInt();
        }
        for(int i=0; i<=N-2; i++){
            C[i] = sc.nextInt();
        }
        for(int i=0; i<=N-1; i++){
            for(int j=1; j<=N; j++){
                if(A[i]==j){
                    bsum = bsum + B[j-1];
                }
            }
        }
        for(int i=1; i<=N-1; i++){
            if(A[i-1]==A[i]-1){
                csum = csum + C[A[i-1]-1];
            }
        }   
        System.out.println(bsum + csum);

    }
}
