import java.util.*;
class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        int[] path = new int[n+1];
        for(int i = 0; i<m; i++) {
            int a = sc.nextInt();
            int b = sc.nextInt();
            if(a==1) path[b]++;
            if(b==1) path[a]++;

            if(a==n) path[b]++;
            if(b==n) path[a]++;
        }
        for(int p : path) {
            if(p==2) {
                System.out.println("POSSIBLE");
                return;
            }
        }
        System.out.println("IMPOSSIBLE");
    }
}
