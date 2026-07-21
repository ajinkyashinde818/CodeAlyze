import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int[] a = new int[n];
        int[] b = new int[n];
        int[] c = new int[n-1];
        for(int i=0; i<n; i++) {
            a[i] = in.nextInt();
        }
        for(int i=0; i<n; i++) {
            b[i] = in.nextInt();
        }
        for(int i=0; i<n-1; i++) {
            c[i] = in.nextInt();
        }

        int s = 0;
        int prev = Integer.MIN_VALUE;
        for(int i=0; i<n; i++) {
            s += b[a[i]-1];
            if(prev+1 == a[i]) {
                s += c[prev-1];
            }
            prev = a[i];
        }
        System.out.println(s);
    }
}
