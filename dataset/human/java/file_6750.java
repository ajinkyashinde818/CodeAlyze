import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int k= sc.nextInt();
        int n= sc.nextInt();
        int max = 0;
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
        }
        
        for (int i = 0; i < n - 1; i++) {
            int dis = Math.abs(a[i+1] - a[i]); 
            max = Math.max(max, dis);
        }
        int ldis = a[0] + k - a[n-1];
        max = Math.max(max, ldis);
        
        System.out.println(k - max);
    }
}
