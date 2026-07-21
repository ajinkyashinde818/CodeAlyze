import java.util.*;

public class Main {

    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int d = sc.nextInt();
        int g = sc.nextInt();
        int[] p = new int[d];
        int[] c = new int[d];
        for (int i = 0; i < d; i++) {
            p[i] = sc.nextInt();
            c[i] = sc.nextInt();
        }
        int ans = dfs(0, new boolean[d], p, c, g, 0);
        System.out.println(ans);

    }

    public static int dfs(int money, boolean[] use, int[] p, int[] c, int g, int u) {
        int min = 99999999;
        for (int id = 0; id < p.length; id++) {
            if (use[id]) {
                continue;
            }
            // 終了する時
            int tmp = g - money;
            int mone = (id + 1) * 100;
            int need = tmp / mone + (tmp % mone == 0 ? 0 : 1);
            if (need > p[id] && mone * p[id] + c[id] >= tmp) {
                min = Math.min(min, u + p[id]);
            } else if (need <= p[id]) {
                min = Math.min(min, u + need);
            } else {
                use[id] = true;
                min = Math.min(dfs(money + p[id] * mone + c[id], use, p, c, g, u + p[id]), min);
                use[id] = false;
            }
        }

        return min;
    }

}
