import java.util.*;
import java.io.*;
import java.util.function.*;



public class Main{
    public static void main(String[] args) {
        FastScanner sc = new FastScanner();
        PrintWriter out = new PrintWriter(System.out);
        String s = sc.next();
        LinkedList<Character> S = new LinkedList<>();
        LinkedList<Character> S_inverse = new LinkedList<>();
        for(int i=0;i<s.length();i++){
            S.add(s.charAt(i));
            S_inverse.add((s.charAt(s.length()-1-i)));
        }
        int q = sc.nextInt();
        for(int i=0;i<q;i++){
            if(sc.nextInt()==1){
                LinkedList<Character> tmp = S;
                S = S_inverse;
                S_inverse = tmp;
            }
            else{
                if(sc.nextInt()==1){
                    char c = sc.next().charAt(0);
                    S.add(0, c);
                    S_inverse.add(c);
                }
                else{
                    char c = sc.next().charAt(0);
                    S.add(c);
                    S_inverse.add(0, c);
                }
            }
        }


        for(Character x : S){
            out.print(x);
        }

        out.println();
        out.flush();
    }

}

@SuppressWarnings("unchecked")
class SegmentTree<T> {
    private BiFunction<T, T, T> f;
    private int n;
    private T d1;
    private T[] dat;
    private  SegmentTree(T[] dat, int n_, BiFunction<T, T, T> f, T d1){
        this.f = f;
        this.d1 = d1;
        init(n_);
        build(dat);
    }

    public SegmentTree(T[] dat, BiFunction<T, T, T> f, T d1){
        this(dat, dat.length, f, d1);
    }

    public SegmentTree(int n_, BiFunction<T, T, T> f, T d1){
        this((T[]) new Object[0], n_, f, d1);
    }

    private void init(int n_){
        n = 1;
        while(n<n_) this.n *= 2;
        this.dat = (T[]) new Object[2 * this.n - 1];
    }

    private void build(T[] v){
        for(int i=0;i<n;i++) dat[i+n-1] = i < v.length ? v[i]: d1;
        for(int i=n-2;i>=0;i--) dat[i] = f.apply(dat[i*2+1], dat[i*2+2]);
    }

    public <E> void update(int k,BiFunction<T,E,T> g, E a){
        k += n-1;
        dat[k] = g.apply(dat[k], a);
        while(k>0){
            k = (k-1)/2;
            dat[k] = f.apply(dat[k*2+1], dat[k*2+2]);
        }
    }

    private T query(int a, int b, int k,int l, int r){
        if(r<=a || b<=l) return d1;
        if(a<=l&&r<=b) return dat[k];
        T vl = query(a, b, k*2+1, l, (l+r)/2);
        T vr = query(a, b, k*2+2, (l+r)/2, r);
        return f.apply(vl, vr);
    }

    public T query(int a, int b){
        return query(a, b, 0, 0, n);
    }
}

class MyMath{
    public static long gcm(long a, long b){

        if(a<b) return gcm(b, a);

        if(a%b==0 || b==0) return b;

        long remainder = a%b;
        return gcm(b, remainder);
    }

    public static long summation(long a, long b){
        return b*(b+1)/2-a*(a-1)/2;
    }

    public static long factorial(long n){

        if(n<=1) return 1;
        else return factorial(n-1)*n;
    }

    public static long binomial(int a, int b){
        if(a<b) return 0;
        long[][] table = new long[a+1][a+1];
        for(int i=0;i<a+1;i++){
            table[0][a] =  0;
            table[i][0] = 1;
            table[i][i] = 1;
        }
        for(int i=1;i<a+1;i++){
            for(int j=1;j<a+1;j++){
                if(i<j) table[i][j] = 0;
                else{
                    table[i][j] = table[i-1][j-1] + table[i-1][j];
                }
            }
        }
        return table[a][b];
    }

    public static long repeatSquarePow(int a, int n, int p){
        if(n==0) return 1;
        if(n==1) return a % p;
        if(n%2==1) return a * repeatSquarePow(a,n-1,p) % p;
        long tmp = repeatSquarePow(a, n/2, p) % p;
        return tmp*tmp % p;
    }

    public static long modinv(long a, long p){
        long b, x, u, q, abs_p, tmp;
        abs_p = Math.abs(p);
        b = p;
        x = 1;
        u = 0;
        while(b > 0){
            q = a / b;
            tmp = u;
            u = x - q*u;
            x = tmp;
            tmp = b;
            b = a - q*b;
            a = tmp;
        }
        return(x < 0) ? abs_p + x: x;
    }
}

class UnionFindTree {
    int[] root;
    int[] rank;
    int[] size;
    public UnionFindTree(int n) {
        this.root = new int[n];
        this.rank = new int[n];
        this.size = new int[n];
        for(int i=0;i<n;i++){
            root[i] = i;
            size[i] = 1;
        }
    }

    public int find(int x){
        if(root[x]==x) return x;
        else{
            return root[x] = find(root[x]);
        }
    }

    public void unite(int x, int y){
        x = find(x);
        y = find(y);
        if(x==y) return;
        if(rank[x] < rank[y]){
            size[find(y)] = size[find(x)];
            root[x] = y;
        }
        else{
            size[find(x)] = size[find(y)];
            root[y] = x;
            if(rank[x]==rank[y]) rank[x]++;
        }
    }

    public boolean same(int x, int y){
        return find(x) == find(y);
    }

    public int size(int i){
        return this.size[find(i)];
    }
}

class graph{
    int[][] graph;
    public graph(int[][] graph){
        this.graph = graph;
    }

    public long dijkstra(int s, int t){
        Integer[] dist = new Integer[graph.length];
        int[] prev = new int[graph.length];
        Arrays.fill(prev, -1);
        PriorityQueue<Integer> manage = new PriorityQueue<>((x,y) -> dist[x]-dist[y]);
        HashSet<Integer> searched = new HashSet<>();
        Arrays.fill(dist,Integer.MAX_VALUE);
        dist[s] = 0;
        searched.add(s);
        for(int i=0;i<graph.length;i++){
            if(graph[s][i]!=Integer.MAX_VALUE){
                dist[i] = graph[s][i];
                prev[i] = s;
                manage.add(i);
            }
        }
        while(manage.size()>0){
            int now = manage.poll();
            searched.add(now);
            for(int i=0;i<graph.length;i++){
                if(graph[now][i]!=Integer.MAX_VALUE){
                    if(!searched.contains(i)){
                        if(dist[i]==Integer.MAX_VALUE){
                            dist[i] = dist[now] + graph[now][i];
                            prev[i] = now;
                            manage.add(i);
                        }
                        else{
                            dist[i] = Math.min(dist[i],dist[now]+graph[now][i]);
                            if(dist[i]==dist[now]+graph[now][i]) prev[i] = now;
                            manage.remove(i);
                            manage.add(i);
                        }
                    }
                }
            }
            if(searched.contains(t)) break;
        }

        return dist[t];
    }

    public boolean judgeBipartitegraph(){
        int[] color = new int[graph.length];
        PriorityQueue<Integer> queue = new PriorityQueue<>();
        HashSet<Integer> visited = new HashSet<>();
        queue.add(0);
        color[0] = 1;
        while(queue.size()>0){
            int now = queue.poll();
            visited.add(now);
            for(int j=0;j<graph[now].length;j++){
                if(visited.contains(j)) continue;
                if(graph[now][j]!=0){
                    if(color[j]==color[now]) return false;
                    queue.add(j);
                    if(color[j]==0) color[j] = -1*color[now];
                }
            }
        }
        return true;
    }

    public int[][] prim(){
        int[] mincost = new int[graph.length];
        boolean[] used = new boolean[graph.length];
        int[][] spanning = new int[graph.length][graph.length];
        for(int i=0;i<graph.length;i++){
            mincost[i] = Integer.MAX_VALUE;
            used[i] = false;
        }
        mincost[0] = 0;
        int totalCost = 0;
        while(true){
            int v = -1;
            for(int u=0;u<graph.length;u++){
                if(!used[u] && (v==-1||mincost[u]<mincost[v])){
                    v = u;
                }
            }
            if(v==-1) break;
            used[v] = true;
            totalCost += mincost[v];
            for(int u=0;u<graph.length;u++){
                if(graph[v][u]<mincost[u]){
                    mincost[u] = graph[v][u];
                }
            }
            for(int u=0;u<graph.length;u++){
                if(mincost[u]==graph[v][u]){
                    spanning[v][u] = 1;
                    spanning[u][v] = 1;
                    break;
                }
            }
        }
        return spanning;
        // return totalCost;
    }

    public int[][] wf(){
        int[][] dist = new int[graph.length][graph.length];
        dist = graph.clone();
        // for(int i=0;i<graph.length;i++){
        //     dist[i][i] = 0;
        // }
        for(int k=0;k<graph.length;k++){
            for(int i=0;i<graph.length;i++){
                for(int j=0;j<graph.length;j++){
                    if(dist[i][k]==Integer.MAX_VALUE || dist[k][j]==Integer.MAX_VALUE) continue;

                    dist[i][j] = Math.min(dist[i][j],dist[i][k]+dist[k][j]);

                }
            }
        }
        for(int i=0;i<graph.length;i++){
            if(dist[i][i]<0) return null;
        }
        return dist;
    }
}

class FastScanner {
    private final InputStream in = System.in;
    private final byte[] buffer = new byte[1024];
    private int ptr = 0;
    private int buflen = 0;
    private boolean hasNextByte() {
        if (ptr < buflen) {
            return true;
        }else{
            ptr = 0;
            try {
                buflen = in.read(buffer);
            } catch (IOException e) {
                e.printStackTrace();
            }
            if (buflen <= 0) {
                return false;
            }
        }
        return true;
    }
    private int readByte() { if (hasNextByte()) return buffer[ptr++]; else return -1;}
    private static boolean isPrintableChar(int c) { return 33 <= c && c <= 126;}
    public boolean hasNext() { while(hasNextByte() && !isPrintableChar(buffer[ptr])) ptr++; return hasNextByte();}
    public String next() {
        if (!hasNext()) throw new NoSuchElementException();
        StringBuilder sb = new StringBuilder();
        int b = readByte();
        while(isPrintableChar(b)) {
            sb.appendCodePoint(b);
            b = readByte();
        }
        return sb.toString();
    }
    public long nextLong() {
        if (!hasNext()) throw new NoSuchElementException();
        long n = 0;
        boolean minus = false;
        int b = readByte();
        if (b == '-') {
            minus = true;
            b = readByte();
        }
        if (b < '0' || '9' < b) {
            throw new NumberFormatException();
        }
        while(true){
            if ('0' <= b && b <= '9') {
                n *= 10;
                n += b - '0';
            }else if(b == -1 || !isPrintableChar(b)){
                return minus ? -n : n;
            }else{
                throw new NumberFormatException();
            }
            b = readByte();
        }
    }
    public int nextInt() {
        long nl = nextLong();
        if (nl < Integer.MIN_VALUE || nl > Integer.MAX_VALUE) throw new NumberFormatException();
        return (int) nl;
    }
    public double nextDouble() { return Double.parseDouble(next());}
}

class BinaryIndexedTree{
    int[] data;
    int[] tree;
    int n;

    public BinaryIndexedTree(int[] data){
        this.data = data;
        this.n = data.length;
        this.tree = new int[n+1];
        buildTree();
    }

    public void buildTree(){
        for(int i=0;i<n;i++){
            add(i+1, data[i]);
        }
    }

    public void add(int index, int value){
        for(int i=index; i<=n; i+=i & -i){
            tree[i] += value;
        }
    }

    public int sum(int from, int to){
        return sum(to) - sum(from-1);
    }

    public int sum(int index){
        int sum = 0;
        for(int i=index; i>0; i-=i & -i){
            sum += tree[i];
        }
        return sum;
    }
}
