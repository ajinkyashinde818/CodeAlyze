import java.util.*;

public class Main {
    public static void main(String args[]) throws Exception {
        Scanner sc = new Scanner(System.in);
        int k = sc.nextInt();
        int n = sc.nextInt();
        int diff = 0;
        int prev = sc.nextInt();
        int x0 = prev;
        for(int i = 1; i < n; i++) {
        	int x = sc.nextInt();
        	diff = Math.max(diff, x - prev);
        	prev = x;
        }
        diff = Math.max(diff, k - prev + x0);
        System.out.println(k - diff);
    }
}
