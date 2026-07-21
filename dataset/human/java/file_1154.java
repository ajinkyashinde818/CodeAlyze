import java.util.*;
 
public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
 
        int N = sc.nextInt();
        int[] a = new int[N];
        long sum = 0;

        for(int i=0; i<N; i++){
            a[i] = sc.nextInt();
            sum += a[i];
        }
        long x = 0;
        long min = 1000000000000000L;
        for(int i=0; i<N-1; i++){
             x += a[i];
             min = Math.min(Math.abs(2 * x - sum), min);
        }
        System.out.println(min);
    }
}
