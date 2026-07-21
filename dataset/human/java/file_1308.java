import java.util.*;

class Main{
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] a = new int[n];
        for(int i = 0; i < n; i++){
            a[i] = sc.nextInt();
        }

        long ans = Long.MAX_VALUE;
        long x = a[0];
        long y = 0;
        for(int i = 1; i < n; i++){
            y += a[i];
        }
        ans = Math.min(ans, Math.abs(x-y));
        if(n > 2) {
            for (int i = 1; i < n-1; i++) {
                x += a[i];
                y -= a[i];
                ans = Math.min(ans, Math.abs(x - y));
            }
        }
        System.out.println(ans);
    }
}
