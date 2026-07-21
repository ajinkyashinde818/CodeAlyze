import java.util.Scanner;
import java.util.Arrays;

public class Main{ public static void main(String...args){
        Scanner sc = new Scanner(System.in); int K = sc.nextInt(); int N = sc.nextInt();
        int[] A = new int[N]; int[] B = new int[N];
        for(int i=0;i <N;i++) A[i]=sc.nextInt();
        Arrays.sort(A);
        for(int i=0;i<N-1;i++) B[i]=A[i+1]-A[i];
        B[N-1] = A[0]+K-A[N-1];
        int maximum = B[0];
        for(int i=0;i<B.length;i++){ if(maximum<B[i]) maximum = B[i];}
        int sol = K-maximum;
        System.out.print(sol);
    }
}
