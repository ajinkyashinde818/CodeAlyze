import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

public class Main {
    char[] ss;
    int st_x;
    int st_y;
    ArrayList<Integer> xs;
    ArrayList<Integer> ys;

    public static void main(String[] args) {
        Main m = new Main();
        m.read();
        m.solve();
    }

    private void read() {
        Scanner sc = new Scanner(System.in);
        ss = sc.nextLine().toCharArray();
        st_x = sc.nextInt();
        st_y = sc.nextInt();
    }

    private void solve() {
        xs = new ArrayList<>();
        ys = new ArrayList<>();
        int st = 0;
        while (st < ss.length && ss[st++] == 'F');
        if (st != ss.length)
            st--;
        st_x -= st;
        boolean flg = false;
        int val = 0;
        for (int i = st; i < ss.length; i++) {
            if (ss[i] == 'T') {
                if (flg) {
                    ys.add(val);
                }
                else {
                    xs.add(val);
                }
                flg = !flg;
                val = 0;
            }
            else
                val++;
        }
        if (st != ss.length) {
            if (flg) {
                ys.add(val);
            } else {
                xs.add(val);
            }
        }

//        System.out.println("x");
//        for (int i: xs)
//            System.out.println(i);
//        System.out.println("y");
//        for (int i: ys)
//            System.out.println(i);
        boolean[] xDp = dp(xs);
        boolean[] yDp = dp(ys);
        if (st_x + 8001 >= 0 && xDp[st_x + 8001] && yDp[st_y + 8001])
            System.out.println("Yes");
        else
            System.out.println("No");
    }

    boolean[] dp(ArrayList<Integer> ls) {
        int n = ls.size();
        boolean[] ret = new boolean[16002];
        boolean[] ret2 = new boolean[16002];
        ret[8001] = true;
        for (int i = 0; i < n; i++) {
            Arrays.fill(ret2, false);
            int t = ls.get(i);
            for (int j = 0; j < ret.length; j++) {
                if (j - t >= 0 && j - t < ret.length)
                    ret2[j] |= ret[j - t];
                if (j + t >= 0 && j + t < ret.length)
                    ret2[j] |= ret[j + t];
            }
            boolean[] tmp = ret2;
            ret2 = ret;
            ret = tmp;
        }
        return ret;
    }
}
