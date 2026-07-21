import java.util.*;
 
public class Main{
    
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);

        int N = sc.nextInt();
        int[] a = new int[N];
        for(int i = 0; i < N; i++){
            a[i] = sc.nextInt();
        }
        sc.close();

        long[] sum = new long[N];
        sum[0] = a[0];
        for(int i = 1; i < N; i++){
            sum[i] = sum[i-1] + a[i];
        }
        long[] diff = new long[N];
        long min = Long.MAX_VALUE;
        for(int i = 0; i < N-1; i++){
            diff[i] = Math.abs(2*sum[i] - sum[N-1]);
            min = Math.min(min, diff[i]);
        }
        System.out.println(min);
    }
}
