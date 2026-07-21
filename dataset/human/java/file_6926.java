import java.util.*;

import java.io.*;


public class Main{
    public static void main(String[] args) {
        FastScanner sc = new FastScanner();
        PrintWriter out = new PrintWriter(System.out);
        int K = sc.nextInt();
        int N = sc.nextInt();
        // int[] A = new int[N];
        ArrayList<Integer> A = new ArrayList<>();
        int res = 0;
        for(int i=0;i<N;i++){
            // A[i] = sc.nextInt();
            A.add(sc.nextInt());
        }
        Collections.sort(A);
        res = Math.max(res, Math.abs(K - A.get(N-1) + A.get(0)));
        for(int i=1;i<N;i++){
            res = Math.max(Math.abs(A.get(i) - A.get(i-1)), res);
        }

        out.println(K-res);
        out.flush();
    }
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

class nextPermutation{
    public static int[] swap(int data[], int left, int right)
    {

        // Swap the data
        int temp = data[left];
        data[left] = data[right];
        data[right] = temp;

        // Return the updated array
        return data;
    }

    // Function to reverse the sub-array
    // starting from left to the right
    // both inclusive
    public static int[] reverse(int data[], int left, int right)
    {

        // Reverse the sub-array
        while (left < right) {
            int temp = data[left];
            data[left++] = data[right];
            data[right--] = temp;
        }

        // Return the updated array
        return data;
    }

    // Function to find the next permutation
    // of the given integer array
    public static boolean findNextPermutation(int data[])
    {

        // If the given dataset is empty
        // or contains only one element
        // next_permutation is not possible
        if (data.length <= 1)
            return false;

        int last = data.length - 2;

        // find the longest non-increasing suffix
        // and find the pivot
        while (last >= 0) {
            if (data[last] < data[last + 1]) {
                break;
            }
            last--;
        }

        // If there is no increasing pair
        // there is no higher order permutation
        if (last < 0)
            return false;

        int nextGreater = data.length - 1;

        // Find the rightmost successor to the pivot
        for (int i = data.length - 1; i > last; i--) {
            if (data[i] > data[last]) {
                nextGreater = i;
                break;
            }
        }

        // Swap the successor and the pivot
        data = swap(data, nextGreater, last);

        // Reverse the suffix
        data = reverse(data, last + 1, data.length - 1);

        // Return true as the next_permutation is done
        return true;
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
