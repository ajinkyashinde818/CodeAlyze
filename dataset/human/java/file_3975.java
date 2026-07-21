import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int[] a = new int[N+1];
        int[] b = new int[N+1];
        int[] c = new int[N];
        for(int i = 1; i <= N; i++) {
            a[i] = sc.nextInt();
        }
        for(int i = 1; i <=  N; i++) {
            b[i] = sc.nextInt();
        }
        for(int i = 1; i < N; i++) {
            c[i] = sc.nextInt();
        }
        
        int sum = 0;
        for(int i = 1; i <= N; i++) {
            sum += b[a[i]];
            if(a[i-1] == a[i] - 1) {
                sum += c[a[i-1]];
            }
        }
        System.out.println(sum);
    }
}
