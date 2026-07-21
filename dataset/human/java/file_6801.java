import java.util.*;
public class Main {
    public static void main(String [] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int K = sc.nextInt();
        int [] A = new int[K];
        for(int i=0;i<K;i++)A[i] = sc.nextInt();
        int min = 999999999;
        for(int i=0;i<K;i++){
            int a1,a2;
            if(i-1>=0) a1 = Math.abs(N-A[i]+A[i-1]);
            else a1 = Math.abs(A[K-1]-A[0]);
            if(i+1<K) a2 = Math.abs(A[i]+N-A[i+1]);
            else a2 = Math.abs(A[K-1]-A[0]);
            if(a1<min) min = a1;
            if(a2<min) min = a2;
        }
        System.out.println(min);
    }
}
