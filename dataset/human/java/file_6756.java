import java.util.*;

public class Main {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);

        int k = sc.nextInt();
        int n = sc.nextInt();

        int[] a = new int[n];
        for(int i=0; i<n; i++) {
            a[i] = sc.nextInt();
        }
        Arrays.sort(a);
        int max = a[0] + k - a[n-1];
        for(int i=0; i<n-1; i++) {
            max = Math.max(max, a[i+1]-a[i]);
        }
        System.out.println(k-max);
    }
}
