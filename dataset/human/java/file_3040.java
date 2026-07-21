import com.sun.corba.se.impl.orbutil.ObjectUtility;

import java.io.*;
import java.lang.reflect.Array;
import java.util.*;

public class Main {

    Random rand = new Random();

    void dfs(int v, int lvl) {
        if (lvl > 2) return;
        if (lvl == 2 && v == n - 1) {
            flag = true;
            return;
        }
        if (used[v]) return;
        used[v] = true;
        for(int i : g[v]){
            dfs(i, lvl + 1);
        }
    }

    boolean used[];
    boolean flag;
    int n;
    ArrayList<Integer> g[];

    public void solve() throws IOException {
        n = nextInt();
        used = new boolean[n];
        g = new ArrayList[n];
        for (int i = 0; i < n; i++) {
            g[i] = new ArrayList<>();
        }
        int m = nextInt();
        for (int i = 0; i < m; i++) {
            int x = nextInt() - 1, y = nextInt() - 1;
            g[x].add(y);
            g[y].add(x);
        }
        dfs(0, 0);
        if(flag){
            out.print("POSSIBLE");
        }else{
            out.print("IMPOSSIBLE");
        }
    }


    BufferedReader br;
    StringTokenizer sc;
    PrintWriter out;

    public static void main(String[] args) throws IOException {
        Locale.setDefault(Locale.US);
        new Main().run();
    }

    void run() throws IOException {
        try {
            br = new BufferedReader(new InputStreamReader(System.in));
            out = new PrintWriter(System.out);
//            br = new BufferedReader(new FileReader("sum2.in"));
//            out = new PrintWriter(new File("sum2.out"));
            solve();
            out.close();
        } catch (Exception e) {
            e.printStackTrace();
            System.exit(1);
        }
    }

    String nextToken() throws IOException {
        while (sc == null || !sc.hasMoreTokens()) {
            try {
                sc = new StringTokenizer(br.readLine());
            } catch (Exception e) {
                return null;
            }
        }
        return sc.nextToken();
    }

    int nextInt() throws IOException {
        return Integer.parseInt(nextToken());
    }
}
