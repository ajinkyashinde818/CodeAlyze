import java.util.*;
import java.io.*;
 
public class Main {
    public static void main(String[] args) throws Exception {
        FastScanner sc = new FastScanner(System.in);
        int xs = sc.nextInt();
        int ys = sc.nextInt();
        int xg = sc.nextInt();
        int yg = sc.nextInt();
        int n = sc.nextInt();
        ArrayList<Circle> li = new ArrayList<>();
        li.add(new Circle(xs,ys,0));
        li.add(new Circle(xg,yg,0));
        for(int i = 0; i < n; i++){
            li.add(new Circle(sc.nextInt(),sc.nextInt(),sc.nextInt()));
        }
        double[][] cost = new double[n+2][n+2];
        for(int i = 0; i < n+2; i++){
            Circle ci = li.get(i);
            for(int j = i+1; j < n+2; j++){
                Circle cj = li.get(j);
                double dx = Math.abs(ci.x-cj.x);
                double dy = Math.abs(ci.y-cj.y);
                cost[i][j] = cost[j][i] = Math.max(0,Math.sqrt(dx*dx+dy*dy)-ci.r-cj.r);
            }
        }
        System.out.println(dijkstra(cost,0,1,n+2));
    }
    public static double dijkstra(double[][] cost , int s, int end,int node) {
        double[] d = new double[node];
        Arrays.fill(d,Long.MAX_VALUE);
        boolean[] used = new boolean[node];
        d[s] = 0;
        while(true){
            int v = -1;
            for(int i = 0; i < node; i++){
                if(!used[i] && v == -1){
                    v = i;
                }else if(!used[i] &&  d[i] < d[v]){
                    v = i;
                }
            }
            if(v == -1) break;
            used[v] = true;
            for(int j = 0; j < node; j++){
                d[j] = Math.min(d[j],d[v]+cost[v][j]);
            }
        }
        return d[end];
    }
}

class Circle{
    int x, y, r;
    public Circle(int x, int y, int r){
        this.x = x;
        this.y = y;
        this.r = r;
    }
}



class FastScanner {
    private BufferedReader reader = null;
    private StringTokenizer tokenizer = null;
    public FastScanner(InputStream in) {
        reader = new BufferedReader(new InputStreamReader(in));
        tokenizer = null;
    }

    public String next() {
        if (tokenizer == null || !tokenizer.hasMoreTokens()) {
            try {
                tokenizer = new StringTokenizer(reader.readLine());
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
        }
        return tokenizer.nextToken();
    }

    public String nextLine() {
        if (tokenizer == null || !tokenizer.hasMoreTokens()) {
            try {
                return reader.readLine();
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
        }
        return tokenizer.nextToken("\n");
    }

    public long nextLong() {
        return Long.parseLong(next());
    }

    public int nextInt() {
        return Integer.parseInt(next());
    }

    public double nextDouble() {
         return Double.parseDouble(next());
    }

    public int[] nextIntArray(int n) {
        int[] a = new int[n];
        for (int i = 0; i < n; i++)
            a[i] = nextInt();
        return a;
    }

    public long[] nextLongArray(int n) {
        long[] a = new long[n];
        for (int i = 0; i < n; i++)
            a[i] = nextLong();
        return a;
    } 
}
