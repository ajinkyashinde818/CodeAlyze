import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        String[] a = new String[n];
        String[] b = new String[m];
        for (int i = 0; i < n; i++) {
            a[i] = sc.next();
        }
        for (int i = 0; i < m; i++) {
            b[i] = sc.next();
        }
        boolean ans = false;
        for (int i = 0; i <= n-m; i++) {
            for (int j = 0; j <= n-m; j++) {
                boolean t = true;
                for (int k = 0; k < m; k++) {
                    if(!a[i+k].substring(j, j+m).contains(b[k])) t = false;
                }
                if(t){
                    ans = true;
                    break;
                }
            }
            if(ans) break;
        }
        System.out.println(ans ? "Yes" : "No");
        sc.close();

    }

}
