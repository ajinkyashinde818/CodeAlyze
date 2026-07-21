import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int k = sc.nextInt();
        int n = sc.nextInt();
        int[] a = new int[n];
        for(int i=0; i<n; i++) {
            a[i] = sc.nextInt();
        }
        int max = 0;
        for(int i=0; i<n; i++) {
            int b;
            if(i == n-1) {
                b = a[0] + k - a[i];
            } else {
                b = a[i+1] - a[i];
            }
            if(b > max) max = b;
        }
        System.out.println(k - max);
    }
}
