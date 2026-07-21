import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int n = scan.nextInt();
        int[] a = new int[n];
        int[] b = new int[n];
        int[] c = new int[n - 1];
        int ans = 0;
        for(int i = 0; i < n; i++) {
        	a[i] = scan.nextInt();
        }
        for(int i = 0; i < n; i++) {
        	b[i] = scan.nextInt();
        	ans += b[i];
        }
        for(int i = 0; i < n - 1; i++) {
        	c[i] = scan.nextInt();
        }

        int temp = a[0];
        for(int i = 1; i < n; i++) {
        	if(a[i] - 1 == temp) {
        		ans += c[temp - 1];
        	}
        	temp = a[i];
        }
        System.out.println(ans);
    }
}
