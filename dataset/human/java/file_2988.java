import java.util.*;

class Main{
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        boolean[] a = new boolean[n+1];
        boolean[] b = new boolean[n+1];
        for(int i = 0; i < m; i++){
            int p = sc.nextInt();
            int q = sc.nextInt();
            if(p == 1) {
                a[q] = true;
            }else if(q == n){
                b[p] = true;
            }
        }
        for(int i = 0; i < n; i++){
            if(a[i] && b[i]){
                System.out.println("POSSIBLE");
                return;
            }
        }
        System.out.println("IMPOSSIBLE");
    }
}
