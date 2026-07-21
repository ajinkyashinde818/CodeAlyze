import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int D = Integer.parseInt(sc.next());
        int G = Integer.parseInt(sc.next());
        int[] p = new int[D];
        int[] c = new int[D];
        int INF = 1_000_000_000;
        for (int i=0;i<D;i++) {
            p[i] = Integer.parseInt(sc.next());
            c[i] = Integer.parseInt(sc.next());
        }
        int ans = INF;
        for (int i=0;i<1<<D;i++) {
            int[] flag = new int[D];
            int cnt = 0;
            int sum = 0;
            for (int j=0;j<D;j++) {
                flag[j] = (i>>j&1);
                if (flag[j]==1) {
                    cnt+=p[j];
                    sum+=p[j]*100*(j+1)+c[j];
                    if (sum>=G) {
                        ans = Math.min(ans, cnt);
                    }
                }
                for (int k=D-1;k>=0;k--) {
                    if (flag[k]==0) {
                        if (G>=sum && (G-sum)<(p[k]*100*(k+1))) {
                            cnt+=(G-sum+100*(k+1)-1)/(100*(k+1));
                            ans = Math.min(ans, cnt);
                        }
                        break;
                    }
                }
            }
        }
        System.out.println(ans);
    }
}
