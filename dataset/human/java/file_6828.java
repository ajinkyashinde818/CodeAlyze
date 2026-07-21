import java.sql.SQLOutput;
import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        int K, N;
        Scanner sc = new Scanner(System.in);
        K = sc.nextInt();
        N = sc.nextInt();
        int[] a = new int[N];
        for(int i = 0 ; i < N ; i++)
        {
            a[i] = sc.nextInt();
        }
        int max = 0;
        Arrays.sort(a);
        for(int i = 0 ; i < a.length - 1; i++)
        {
            max = Math.max(max,Math.min(a[i+1]-a[i],K-a[i+1]+a[i]) );

        }
        max=Math.max(max,Math.min(a[N-1]-a[0],K-a[N-1]+a[0]));
        System.out.println(K - max);
    }
}
