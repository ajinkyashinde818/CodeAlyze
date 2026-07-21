import java.util.Scanner;

public class Main {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int k = sc.nextInt();
        int n = sc.nextInt();
        int[] a = new int[n];
        int max_dist = 0;
        for(int i = 0; i < n; i++){
            a[i] = sc.nextInt();
        }
        sc.close();
        max_dist = a[0] + (k - a[n - 1]);
        for(int i = 0; i < n - 1; i++){
            max_dist = Math.max(max_dist, a[i + 1] - a[i]);
        }
        System.out.println(k - max_dist);
    }
}
