import java.io.*;
import java.util.*;

@SuppressWarnings("unused")
public class Main {
    FastScanner in;
    PrintWriter out;
    int MOD = (int)1e9+7;
    long ceil(long a, long b){return (a + b - 1) / b;}
    long gcd(long a, long b){return b == 0 ? a : gcd(b, a % b);}
    long lcm(long a, long b){return a / gcd(a, b) * b;}

    void solve(){
        double[] s = in.nextDoubleArray(2), t = in.nextDoubleArray(2);
        int N = in.nextInt();
        double[][] xyr = new double[N][3];
        for(int i = 0; i < N; i++) xyr[i] = in.nextDoubleArray(3);

        ArrayList<ArrayList<Edge>> g = new ArrayList<>();
        for(int i = 0; i < N+2; i++) g.add(new ArrayList<>());
        for(int i = 0; i < N; i++){
            for (int j = i+1; j < N; j++) {
                double d = Math.max(0, Math.hypot(xyr[i][0] - xyr[j][0], xyr[i][1] - xyr[j][1]) - xyr[i][2] - xyr[j][2]);
                g.get(i).add(new Edge(i, j, d));
                g.get(j).add(new Edge(j, i, d));
            }
            double ds = Math.max(0, Math.hypot(xyr[i][0] - s[0], xyr[i][1] - s[1]) - xyr[i][2]);
            g.get(N).add(new Edge(N, i, ds));
            double dt = Math.max(0, Math.hypot(xyr[i][0] - t[0], xyr[i][1] - t[1]) - xyr[i][2]);
            g.get(i).add(new Edge(i, N+1, dt));
        }
        double dst = Math.hypot(s[0] - t[0], s[1] - t[1]);
        g.get(N).add(new Edge(N, N+1, dst));

        double[] res = dijkstra(g, N);
        out.println(res[N+1]);
    }

    double[] dijkstra(ArrayList<ArrayList<Edge>> g, int start){
        double INF = Double.MAX_VALUE / 2;
        double[] dist = new double[g.size()];
        Arrays.fill(dist, INF);
        dist[start] = 0;
        PriorityQueue<Node> priorityQueue = new PriorityQueue<Node>();
        priorityQueue.add(new Node(start, 0));

        while(!priorityQueue.isEmpty()){
            Node node = priorityQueue.poll();
            if(dist[node.index] < node.cost) continue;
            for(Edge e : g.get(node.index)){
                if(dist[e.to] > dist[node.index] + e.cost){
                    dist[e.to] = dist[node.index] + e.cost;
                    priorityQueue.add(new Node(e.to, dist[e.to]));
                }
            }
        }

        return dist;
    }

    class Node implements Comparable<Node>{
        int index;
        double cost;
        public Node(int i, double c){
            index = i; cost = c;
        }
        @Override
        public int compareTo(Node o) {
            return Double.compare(this.cost, o.cost);
        }
    }

    class Edge implements Comparable<Edge>{
        int from;
        int to;
        double cost;
        public Edge(int f, int t, double c){
            from = f;to = t;cost = c;
        }
        @Override
        public int compareTo(Edge o) {
            return Double.compare(this.cost, o.cost);
        }
    }

    public static void main(String[] args) {
        new Main().m();
    }

    private void m() {
        in = new FastScanner(System.in);
        out = new PrintWriter(System.out);
        /*
        try {
            String path = "output.txt";
            out = new PrintWriter(new BufferedWriter(new FileWriter(new File(path))));
        }catch (IOException e){
            e.printStackTrace();
        }
        */
        solve();
        out.flush();
        in.close();
        out.close();
    }

    static class FastScanner {
        private Reader input;

        public FastScanner() {this(System.in);}
        public FastScanner(InputStream stream) {this.input = new BufferedReader(new InputStreamReader(stream));}
        public void close() {
            try {
                this.input.close();
            } catch (IOException e) {
                e.printStackTrace();
            }
        }

        public int nextInt() {return (int) nextLong();}

        public long nextLong() {
            try {
                int sign = 1;
                int b = input.read();
                while ((b < '0' || '9' < b) && b != '-' && b != '+') {
                    b = input.read();
                }
                if (b == '-') {
                    sign = -1;
                    b = input.read();
                } else if (b == '+') {
                    b = input.read();
                }
                long ret = b - '0';
                while (true) {
                    b = input.read();
                    if (b < '0' || '9' < b) return ret * sign;
                    ret *= 10;
                    ret += b - '0';
                }
            } catch (IOException e) {
                e.printStackTrace();
                return -1;
            }
        }

        public double nextDouble() {
            try {
                double sign = 1;
                int b = input.read();
                while ((b < '0' || '9' < b) && b != '-' && b != '+') {
                    b = input.read();
                }
                if (b == '-') {
                    sign = -1;
                    b = input.read();
                } else if (b == '+') {
                    b = input.read();
                }
                double ret = b - '0';
                while (true) {
                    b = input.read();
                    if (b < '0' || '9' < b) break;
                    ret *= 10;
                    ret += b - '0';
                }
                if (b != '.') return sign * ret;
                double div = 1;
                b = input.read();
                while ('0' <= b && b <= '9') {
                    ret *= 10;
                    ret += b - '0';
                    div *= 10;
                    b = input.read();
                }
                return sign * ret / div;
            } catch (IOException e) {
                e.printStackTrace();
                return Double.NaN;
            }
        }

        public char nextChar() {
            try {
                int b = input.read();
                while (Character.isWhitespace(b)) {
                    b = input.read();
                }
                return (char) b;
            } catch (IOException e) {
                e.printStackTrace();
                return 0;
            }
        }

        public String nextStr() {
            try {
                StringBuilder sb = new StringBuilder();
                int b = input.read();
                while (Character.isWhitespace(b)) {
                    b = input.read();
                }
                while (b != -1 && !Character.isWhitespace(b)) {
                    sb.append((char) b);
                    b = input.read();
                }
                return sb.toString();
            } catch (IOException e) {
                e.printStackTrace();
                return "";
            }
        }

        public String nextLine() {
            try {
                StringBuilder sb = new StringBuilder();
                int b = input.read();
                while (b != -1 && b != '\n') {
                    sb.append((char) b);
                    b = input.read();
                }
                return sb.toString();
            } catch (IOException e) {
                e.printStackTrace();
                return "";
            }
        }

        public int[] nextIntArray(int n) {
            int[] res = new int[n];
            for (int i = 0; i < n; i++) {
                res[i] = nextInt();
            }
            return res;
        }

        public int[] nextIntArrayDec(int n) {
            int[] res = new int[n];
            for (int i = 0; i < n; i++) {
                res[i] = nextInt() - 1;
            }
            return res;
        }

        public int[] nextIntArray1Index(int n) {
            int[] res = new int[n + 1];
            for (int i = 0; i < n; i++) {
                res[i + 1] = nextInt();
            }
            return res;
        }

        public long[] nextLongArray(int n) {
            long[] res = new long[n];
            for (int i = 0; i < n; i++) {
                res[i] = nextLong();
            }
            return res;
        }

        public long[] nextLongArrayDec(int n) {
            long[] res = new long[n];
            for (int i = 0; i < n; i++) {
                res[i] = nextLong() - 1;
            }
            return res;
        }

        public long[] nextLongArray1Index(int n) {
            long[] res = new long[n + 1];
            for (int i = 0; i < n; i++) {
                res[i + 1] = nextLong();
            }
            return res;
        }

        public double[] nextDoubleArray(int n) {
            double[] res = new double[n];
            for (int i = 0; i < n; i++) {
                res[i] = nextDouble();
            }
            return res;
        }
    }
}
