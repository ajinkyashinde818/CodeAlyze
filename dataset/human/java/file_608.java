import java.util.*;
import java.util.function.*;
import java.util.stream.*;
import java.util.Map.Entry;
// import static java.util.Arrays.compare;
import static java.util.Arrays.fill;
import static java.util.Arrays.sort;
import static java.util.Collections.sort;
import static java.util.Comparator.reverseOrder;
// import static java.util.List.of;
import static java.util.Objects.isNull;
import static java.util.Objects.nonNull;
import static java.util.Objects.hash;

import java.io.*;

import java.math.BigInteger;
import static java.math.BigInteger.ZERO;
import static java.math.BigInteger.ONE;
// import static java.math.BigInteger.TWO;
import static java.math.BigInteger.TEN;

import static java.lang.Math.PI;
import static java.lang.Math.E;
import static java.lang.Math.min;
import static java.lang.Math.max;
import static java.lang.Math.abs;
import static java.lang.Math.sin;
import static java.lang.Math.cos;
import static java.lang.Math.tan;
import static java.lang.Math.asin;
import static java.lang.Math.acos;
import static java.lang.Math.atan;
import static java.lang.Math.atan2;
import static java.lang.Math.hypot;
import static java.lang.Math.sqrt;
import static java.lang.Math.log;
import static java.lang.Math.exp;
import static java.lang.String.format;
import static java.lang.System.exit;
import static java.lang.System.currentTimeMillis;

public class Main{
   public static void main(String[] args) {
      FastScanner fsc = new FastScanner();
      int n=fsc.nextInt();
      int r=fsc.nextInt();
      if(n>=10){
         System.out.println(r);
      } else{
         System.out.println(r+100*(10-n));
      }
   }
}


class ArrayUtil{
    public static int[] map(IntUnaryOperator op, int[] a){
        int[] b=new int[a.length];
        for(int i=0;i<a.length;i++) b[i] = op.applyAsInt(a[i]);
        return b;
    }
    /**
     * s[i] is the sum of the range [0, i) in a.
     * @param a
     * @return cumulative sum array of a.
     */
    public static int[] cumsum(int[] a){
        int n=a.length;
        int[] s=new int[n+1];
        for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i-1];
        return s;
    }
    public static int[][] cumsum(int[][] a){
        int n=a.length;
        int m=a[0].length;
        int[][] s=new int[n+1][m+1];
        for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1]+a[i-1][j-1];
        return s;
    }
    public static void reverse(int[] a, int begin, int end){
        for(int i=begin;i<begin+(end-begin)/2;i++) swap(a, i, begin+end-i-1);
    }
    public static void reverse(int[] a){
        reverse(a, 0, a.length);
    }
    public static void revSort(int[] a){
        Arrays.sort(a);
        reverse(a);
    }
    public static int[] nextPermutation(int[] a){
        int[] ret=a.clone();
        int n=ret.length;
        for(int i=n-1;i>=1;i--){
            if(ret[i]>ret[i-1]){
                int fail=n, pass=i;
                while(fail-pass>1){
                    int mid=pass+(fail-pass)/2;
                    if(ret[mid]>ret[i-1]) pass=mid;
                    else fail=mid;
                }
                swap(ret, pass, i-1);
                reverse(ret, i, n);
                return ret;
            }
        }
        return null;
    }
    public static int[] predPermutation(int[] a){
        int[] ret=a.clone();
        int n=ret.length;
        for(int i=n-1;i>=1;i--){
            if(ret[i]<ret[i-1]){
                int fail=n, pass=i;
                while(fail-pass>1){
                    int mid=pass+(fail-pass)/2;
                    if(ret[mid]<ret[i-1]) pass=mid;
                    else fail=mid;
                }
                swap(ret, pass, i-1);
                reverse(ret, i, n);
                return ret;
            }
        }
        return null;
    }
    public static void swap(int[] a, int u, int v){
        int tmp=a[u];
        a[u]=a[v];
        a[v]=tmp;
    }
    public static int compare(int[] a, int[] b){
        for(int i=0;i<a.length;i++){
            if(i>=b.length){
                return -1;
            } else if(a[i]>b[i]){
                return 1;
            } else if(a[i]<b[i]){
                return -1;
            }
        }
        if(a.length<b.length){
            return 1;
        } else{
            return 0;
        }
    }
    public static boolean equals(int[] a, int[] b){
        return compare(a, b)==0;
    }

    /*      IntArray
     * _________________________
     *      LongArray
     */
    public static long[] map(LongUnaryOperator op, long[] a){
        long[] b=new long[a.length];
        for(int i=0;i<a.length;i++) b[i]=op.applyAsLong(a[i]);
        return b;
    }
    /**
     * s[i] is the sum of the range [0, i) in a.
     * @param a
     * @return cumulative sum array of a.
     */
    public static long[] cumsum(long[] a){
        int n=a.length;
        long[] s=new long[n+1];
        for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i-1];
        return s;
    }
    public static long[][] cumsum(long[][] a){
        int n=a.length;
        int m=a[0].length;
        long[][] s=new long[n+1][m+1];
        for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1]+a[i-1][j-1];
        return s;
    }
    public static void reverse(long[] a, int begin, int end){
        for(int i=begin;i<begin+(end-begin)/2;i++) swap(a, i, begin+end-i-1);
    }
    public static void reverse(long[] a){
        reverse(a, 0, a.length);
    }
    public static void revSort(long[] a){
        Arrays.sort(a);
        reverse(a);
    }
    public static void compress(long[] a){
        int n=a.length;
        long[] sorted = a.clone();
        Arrays.sort(sorted);
        for(int i=0;i<n;i++){
            int l=0, r=n;
            while(r-l>1){
                int m=l+(r-l)/2;
                if(sorted[m]<=a[i]) l=m;
                else r=m;
            }
            a[i]=l;
        }
    }
    public static void swap(long[] a, int u, int v){
        long tmp=a[u];
        a[u]=a[v];
        a[v]=tmp;
    }
    public static int compare(long[] a, long[] b){
        for(int i=0;i<a.length;i++){
            if(i>=b.length){
                return -1;
            } else if(a[i]>b[i]){
                return 1;
            } else if(a[i]<b[i]){
                return -1;
            }
        }
        if(a.length<b.length){
            return 1;
        } else{
            return 0;
        }
    }
    public static boolean equals(long[] a, long[] b){
        return compare(a, b)==0;
    }
}


class BellmanFord{
    public long[] bellmanFord(Node[] nodes, int s){
        int n = nodes.length;
        boolean negativeLoop[] = new boolean[n];
        long[] d = new long[n];
        fill(d, Const.LINF);
        d[s] = 0;
        for(int i = 0; i < n; i++){
            for(int from = 0; from < n; from++){
                for(Edge edge: nodes[from].edges){
                    int to = edge.to;
                    long c = edge.cost;
                    if(d[to] > d[from] + c){
                        d[to] = d[from] + c;
                    }
                }
            }
        }           
        for(int i = 0; i < n; i++){
            for(int from = 0; from < n; from++){
                for(Edge edge: nodes[from].edges){
                    int to = edge.to;
                    long c = edge.cost;
                    if(d[to] > d[from] + c){
                        negativeLoop[to] = true;
                        d[to] = -Const.LINF;
                    }
                    if(negativeLoop[from]){
                        negativeLoop[to] = true;
                        d[to] = -Const.LINF;
                    }
                }
            }
        }
        return d;
    }
}

/**
 * BinaryIndexedTree(n=10): [ 8 ] [ 4 ] [ 2 ] [ 6 ] [ 10 ] [1] [3] [5] [7] [9]
 * 
 * original array: (1, 2, 3, 4, 5, 6, 7, 8, 9, 10)
 * 
 * if you want to get the sum of range (l, r], caluculate S(r)-S(l). (S(n) means
 * \sum_{i=1}^n array[i].)
 * 
 * then, you need to be able to calculate S(n) quickly. actually, you can.
 * 
 * 1. binarize n. Ex: n=5(10)=101(2). 2. decompose
 * n=2**p_1+2**p_2+...+2**p_m.(p_1<...<p_m) Ex: n=1+100. 3. acutually,
 * S(n)=\sum_{i=1}^m{tree[\sum_{j=i}^m 2**p_j]} Ex: S(n)=tree[101]+tree[100].
 * 
 * computational complexity of sum-query is O(log n).
 */

class BinaryIndexedTree{
    private int[] tree;
    private int[] originalArray;
    private int n;
    /**
     * @param array 0-indexed array.
     */
    public BinaryIndexedTree(int[] array){
        this.originalArray = array.clone();
        this.n = array.length;
        this.tree = new int[n+1];
        init();
    }
    public BinaryIndexedTree(int initial, int n){
        this.originalArray = new int[n];
        this.n = n;
        this.tree = new int[n+1];
        for(int i = 0; i < n; i++) originalArray[i] = initial;
        init();
    }
    public BinaryIndexedTree(int n){
        this(0, n);
    }
    private void init(){
        for(int i = 1; i <= n; i++){
            tree[i] += originalArray[i-1];
            int parent = i + (-i & i);
            if(parent <= n) tree[parent] += tree[i];
        }
    }

    /**
     * Calculate the sum of range (l, r] in array (1-indexed).
     * @param l left border (open)
     * @param r right border (closed)
     * @return sum of range (l, r] in array (1-indexed).
     */
    public int sum(int l, int r){
        return sum(r) - sum(l);
    }
    public int sum(int r){
        int ret = 0;
        for(; r > 0; r -= -r & r) ret += tree[r];
        return ret;
    }
    public int sum(){
        return sum(n);
    }

    /**
     * add v to array[i] and update BIT.
     * @param i index of array (1-indexed)
     * @param v adding value
     */
    public void add(int i, int v){
        originalArray[i-1] += v;
        for(; i <= n; i += -i & i) tree[i] += v;
    }

    /**
     * update the value of array[i] to v and update BIT.
     * @param i index of array (1-indexed)
     * @param v adding value
     */
    public void update(int i, int v){
        add(i, v - originalArray[i-1]);
        originalArray[i] = v;
    }

    @Override
    public String toString(){
        int msb=0;
        for(int m=n;m>>1!=0;m>>=1, msb++);
        char[][] c=new char[msb+1][1<<(2*msb+1)];
        int[] indx=new int[msb+1];
        for(int i=1;i<=n;i++){
            int j=0;
            for(int l=-i&i;l>>1!=0;l>>=1, j++);
            char[] intc=Integer.toString(tree[i]).toCharArray();
            int intl=intc.length;
            c[j][indx[j]]='[';
            c[j][indx[j]+(1<<(j+2))-1]=']';
            int st=indx[j]+(1<<(j+1))-intl/2-1;
            for(int l=0;l<intl;l++){
                c[j][st+l]=intc[l];
            }
            indx[j]+=1<<(j+3);
        }
        StringBuilder sb=new StringBuilder();
        for(int i=msb;i>=0;sb.append(String.valueOf(c[i--])).append("\n"));
        return sb.toString();
    }
}

class Const{
    public static final long MOD7 = 1_000_000_007;
    public static final long MOD9 = 1_000_000_009;
    public static long MOD = MOD7;
    public static final long LINF = 1_000_000_000_000_000_000l;
    public static final int IINF = 1_000_000_000;
    public static void setMod(long mod){
        MOD = mod;
    }
}


class Dijkstra{
    public static PrevAndDist dijkstra(Node[] nodes, int s){
        int n = nodes.length;
        int[] prev = new int[n];
        long[] d = new long[n];
        Queue<Integer> pq = new PriorityQueue<>((u, v) -> Long.compare(d[u], d[v]));
        fill(d, Const.LINF);
        d[s] = 0;
        pq.add(s);
        while(pq.size() > 0){
            int now = pq.poll();
            for(Edge e: nodes[now].edges){
                int next = e.to;
                long c = e.cost;
                if(d[now] + c < d[next]){
                    d[next] = d[now] + c;
                    prev[next] = now;
                    pq.add(next);
                }
            }
        }
        return new PrevAndDist(prev, d);
    }

    public static int[] path(PrevAndDist pd, int from, int to){
        ArrayList<Integer> rev=new ArrayList<>();
        for(int now = to; now != from; now = pd.prev[now]) rev.add(now);
        rev.add(from);
        int[] path = new int[rev.size()];
        for(int i = 0; i < path.length; i++) path[i] = rev.get(path.length - i - 1);
        return path;
    }

    public static class PrevAndDist{
        public int[] prev;
        public long[] d;
        public PrevAndDist(int[] prev, long[] d){
            this.prev=prev;
            this.d=d;
        }
    }
}


//caluculate maximum-flow in O(|E|*|V|^2), but often fast.
class Dinic{
    public static long dinic(int s, int t, Node[] nodes) {
        long flow = 0;
        while(true){
            int[] level = bfs(s, t, nodes);
            if(level[t] < 0) break;
            int[] iter = new int[nodes.length];
            long f = dfs(s, t, nodes, Const.LINF, level, iter);
            while (f > 0) {
                flow += f;
                f = dfs(s, t, nodes, Const.LINF, level, iter);
            }
        }
        return flow;
    }

    private static int[] bfs(int s, int t, Node[] nodes) {
        IntQueue iq = new IntQueue(nodes.length);
        iq.addLast(s);
        int[] level = new int[nodes.length];
        fill(level, -1);
        level[s] = 0;
        while (iq.size() > 0) {
            int now = iq.pollFirst();
            for (Edge e : nodes[now].edges) {
                if (level[e.to] < 0 && e.cap > 0) {
                    iq.addLast(e.to);
                    level[e.to] = level[now] + 1;
                }
            }
        }
        return level;
    }

    private static long dfs(int now, int t, Node[] nodes, long f, int[] level, int[] iter) {
        if (now == t) return f;
        for (int i = iter[now]++; i < nodes[now].edges.size(); i++) {
            Edge e = nodes[now].edges.get(i);
            if (level[now] < level[e.to] && e.cap > 0) {
                long d = dfs(e.to, t, nodes, Math.min(f, e.cap), level, iter);
                if (d > 0) {
                    e.cap -= d;
                    nodes[e.to].edges.get(e.rev).cap += d;
                    return d;
                }
            }
        }
        return 0;
    }
}

class Edge{
    public int from, to;
    public long cost;
    public long cap;
    public int rev;
    public Edge(int to, long cap, int rev) {
        this.to = to;
        this.cap = cap;
        this.rev = rev;
    }
    public Edge(int from, int to, long cost){
        this.from = from;
        this.to = to;
        this.cost=cost;
    }
    public Edge(int from, int to){
        this.from = from;
        this.to = to;
    }
    public Edge(int to, long cost){
        this.to = to;
        this.cost = cost;
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

// caluculate maximum-flow in O(|E|*F). F is the maximum-flow.
class FordFulkerson{
    static long fordFulkerson(int s, int t, Node[] nodes) {
        long flow = 0;
        while (true) {
            boolean[] used = new boolean[nodes.length];
            long f = dfs(s, t, nodes, Const.LINF, used);
            flow += f;
            if(f <= 0) break;
        }
        return flow;
    }

    private static long dfs(int now, int t, Node[] nodes, long f, boolean[] used) {
        if(now == t) return f;
        used[now] = true;
        for (int i = 0; i < nodes[now].edges.size(); i++) {
            Edge e = nodes[now].edges.get(i);
            if (!used[e.to] && e.cap > 0) {
                long d = dfs(e.to, t, nodes, Math.min(f, e.cap), used);
                if (d > 0) {
                    e.cap -= d;
                    nodes[e.to].edges.get(e.rev).cap += d;
                    return d;
                }
            }
        }
        return 0;
    }
}

class Graph{
    public Node[] nodes;
    public Edge[] edges;
    public int n;
    public int m;

    private int mIndx = 0;

    public Graph(int n, int m){
        this.nodes = new Node[n];
        for(int i = 0; i < n; i++) nodes[i] = new Node(i);
        this.edges = new Edge[m];
        this.n = n;
        this.m = m;
    }

    public void addDirectedEdge(int from, int to, long cost){
        Edge e = new Edge(from, to, cost);
        nodes[from].edges.add(e);
        nodes[to].in++;
        edges[mIndx++] = e;
    }
    public void addNonDirectedEdge(int from, int to, long cost){
        Edge e = new Edge(from, to, cost);
        Edge er = new Edge(to, from, cost);
        nodes[from].edges.add(e);
        nodes[to].edges.add(er);
        nodes[from].in++;
        nodes[to].in++;
        edges[mIndx++] = e;
    }
    public void addDirectedEdge(int from, int to){
        addDirectedEdge(from, to, 1l);
    }
    public void addNonDirectedEdge(int from, int to){
        addNonDirectedEdge(from, to, 1l);
    }
    public void addCapEdge(int from, int to, long cap) {
        nodes[from].edges.add(new Edge(to, cap, nodes[to].edges.size()));
        nodes[to].edges.add(new Edge(from, 0l, nodes[from].edges.size() - 1));
    }
    public void setNodeWeight(long[] w){
        for(int i = 0; i < n; i++) nodes[i].w = w[i];
    }
}

class IntQueue {
    private int[] a;
    private int head = 0, tail = 0;

    public IntQueue(int max) {
        a = new int[max+2];
    }
    public void addLast(int x) {
        a[tail++] = x;
    }
    public int pollFirst() {
        if(tail == head) {
            try { throw new Exception("no elements."); } 
            catch (Exception e) { e.printStackTrace(); }
        }
        return a[head++];
    }
    public int pollLast() {
        if(tail == head) {
            try { throw new Exception("no elements."); } 
            catch (Exception e) { e.printStackTrace(); }
        }
        return a[--tail];
    }
    public int getFirst() {
        return a[head];
    }
    public int getLast() {
        return a[tail - 1];
    }
    public int size() {
        return tail - head;
    }
    public void init() {
        head = tail = 0;
    }
}


class IntUtil {
    public static int min(int... a) {
        int ret = Const.IINF;
        for (int c : a) ret = Math.min(ret, c);
        return ret;
    }

    public static int max(int... a) {
        int ret = -Const.IINF;
        for (int c : a) ret = Math.max(ret, c);
        return ret;
    }

    /**
     * Caluculate the ceil of a/b. Returns the smallest integer greater than or
     * equal to a/b while 'a/b' rounds fractional parts to ZERO.
     * 
     * @param a
     * @param b
     * @return the smallest integer greater than or equal to a/b
     */
    public static int cld(int a, int b) {
        if (a > 0 && b > 0) return (a + b - 1) / b;
        else if (a < 0 && b < 0) return (a + b + 1) / b;
        else return a / b;
    }

    /**
     * Caluculate the floor of a/b. Returns the largest integer less than or equal
     * to a/b while 'a/b' rounds fractional parts to ZERO.
     * 
     * @param a
     * @param b
     * @return the largest integer less than or equal to a/b
     */
    public static int fld(int a, int b) {
        if (a <= 0 && b > 0) return (a - b + 1) / b;
        else if (a > 0 && b <= 0) return (a - b - 1) / b;
        else return a / b;
    }

    public static int fold(IntBinaryOperator func, int a, int... b) {
        int ret = a;
        for (int c : b) ret = func.applyAsInt(ret, c);
        return ret;
    }
}


class LazySegmentTree{
    private long[] tree;
    private long[] lazy;
    private long idElm;
    private long defaultLazyValue;
    private LongBinaryOperator operator;
    private LongBinaryOperator updateFunction;
    private LongBinaryOperator mergeLazyFunction;
    private BiFunction<Long, Integer, Long> collapseUpdateFunction;
    private int size;
    private int leafs;
    private int height;
    private int baseOfLeaf;

    public LazySegmentTree(long[] t, LongBinaryOperator operator, long idElm, LongBinaryOperator updateFunction, LongBinaryOperator mergeLazyFunction , BiFunction<Long, Integer, Long> collapseUpdateFunction, long defaultLazyValue){
        int n = t.length;
        this.operator = operator;
        this.idElm = idElm;
        this.updateFunction = updateFunction;
        this.mergeLazyFunction = mergeLazyFunction;
        this.collapseUpdateFunction = collapseUpdateFunction;
        this.defaultLazyValue = defaultLazyValue;
        this.height = minimumPowerOfTwo(n);
        this.leafs = 1 << this.height;
        this.baseOfLeaf = this.leafs - 1;
        this.size = 2 * this.leafs - 1;
        this.lazy = new long[this.size];
        this.tree = new long[this.size];
        for(int i = size - 1; i >= 0; i--) {
            if(i >= baseOfLeaf + n) {
                this.tree[i] = this.idElm;
            } else if(isLeaf(i)) {
                this.tree[i] = t[i - baseOfLeaf];
            } else{
                this.tree[i] = operator.applyAsLong(this.tree[left(i)], this.tree[right(i)]);
            }
        }
    }

    public void applyForSegment(int l, int r, long v){
        applyForSegment(new Range(l, r), 0, new Range(0, leafs), v);
    }
    private long applyForSegment(Range queryRange, int k, Range treeRange, long v){
        evaluate(k, treeRange);
        if(queryRange.crosses(treeRange)) {
            if(queryRange.contains(treeRange)) {
                lazy[k] = mergeLazyFunction.applyAsLong(lazy[k], v);
                return updateFunction.applyAsLong(tree[k], collapseUpdateFunction.apply(lazy[k], treeRange.length()));
            } else {
                long left = applyForSegment(queryRange, left(k), treeRange.leftHalf(), v);
                long right = applyForSegment(queryRange, right(k), treeRange.rightHalf(), v);
                return tree[k] = operator.applyAsLong(left, right);
            }
        } else{
            return tree[k];
        }
    }
    public void applyForPoint(int i, long v){
        tree[baseOfLeaf + i] = updateFunction.applyAsLong(tree[baseOfLeaf + i], collapseUpdateFunction.apply(v, 1));
    }

    public long query(int l, int r){
        return query(new Range(l, r), 0, new Range(0, leafs));
    }
    private long query(Range queryRange, int k, Range treeRange){
        evaluate(k, treeRange);
        if(!queryRange.crosses(treeRange)){
            return idElm;
        } else if(queryRange.contains(treeRange)){
            return tree[k];
        } else{
            long left = query(queryRange, left(k), treeRange.leftHalf());
            long right = query(queryRange, right(k), treeRange.rightHalf());
            return operator.applyAsLong(left, right);
        }
    }
    private void evaluate(int k, Range r){
        if(lazy[k] != defaultLazyValue) {
            if(!isLeaf(k)){
                lazy[left(k)] = mergeLazyFunction.applyAsLong(lazy[left(k)], lazy[k]);
                lazy[right(k)] = mergeLazyFunction.applyAsLong(lazy[right(k)], lazy[k]);
            }
            tree[k] = updateFunction.applyAsLong(tree[k], collapseUpdateFunction.apply(lazy[k], r.length()));
            lazy[k] = defaultLazyValue;
        }
    }
    private int minimumPowerOfTwo(int n){
        int i = 0;
        while(1 << ++i < n);
        return i;
    }
    private boolean isLeaf(int i){
        return i >= baseOfLeaf;
    }
    private int left(int k){
        return 2 * k + 1;
    }
    private int right(int k){
        return 2 * k + 2;
    }

    public String toString(){
        StringBuilder sb = new StringBuilder();
        for(int h = 0; h <= height; h++) {
            for(int i = (1 << h) - 1; i < (1 << (h + 1)) - 1; i++) {
                sb.append(tree[i]).append(" ");
            }
            sb.append('\n');
        }
        return sb.toString();
    }

    public static enum QueryFunctions{
        SUM((u, v) -> u + v, 0),
        // PRODUCT((u, v) -> u * v, 1),
        MAX((u, v) -> u > v ? u : v, Long.MIN_VALUE),
        MIN((u, v) -> u < v ? u : v, Long.MAX_VALUE),
        // GCD((u, v) -> gcd(u, v), 0),
        // LCM((u, v) -> lcm(u, v), 1),
        ;
        private final LongBinaryOperator queryFunction;
        private final long idElm;
        private QueryFunctions(LongBinaryOperator queryFunction, long idElm){
            this.queryFunction = queryFunction;
            this.idElm = idElm;
        }
        public LongBinaryOperator getQueryFunction(){
            return queryFunction;
        }
        public long getIdElm(){
            return idElm;
        }
    }
    public static enum UpdateFunctions{
        ADD((u, v) -> u + v, (u, v) -> u + v, (u, l) -> u * l, 0),
        SUB((u, v) -> u - v, (u, v) -> u + v, (u, l) -> u * l, 0),
        // MUL((u, v) -> u * v, (u, v) -> u * v, (u, l) -> u, 1),
        REWRITE((u, v) -> v, (u, v) -> v, (u, l) -> u, Long.MIN_VALUE + 1),
        ;
        private final LongBinaryOperator updateFunction;
        private final LongBinaryOperator mergeLazyFunction;
        private final BiFunction<Long, Integer, Long> collapseUpdateFunction;
        private final long defaultLazyValue;
        private UpdateFunctions(LongBinaryOperator updateFunction, LongBinaryOperator mergeLazyFunction, BiFunction<Long, Integer, Long> collapseUpdateFunction, long defaultLazyValue){
            this.updateFunction = updateFunction;
            this.mergeLazyFunction = mergeLazyFunction;
            this.collapseUpdateFunction = collapseUpdateFunction;
            this.defaultLazyValue = defaultLazyValue;
        }
        public LongBinaryOperator getUpdateFunction(){
            return updateFunction;
        }
        public LongBinaryOperator getMergeLazyFunction(){
            return mergeLazyFunction;
        }
        public BiFunction<Long, Integer, Long> getCollapseUpdateFunction(){
            return collapseUpdateFunction;
        }
        public long getDefaultLazyValue(){
            return defaultLazyValue;
        }
    }
    public static LazySegmentTree create(long[] t, QueryFunctions queryFunctionCode, UpdateFunctions updateFunctionCode){
        LongBinaryOperator operator = queryFunctionCode.getQueryFunction();
        long idElm = queryFunctionCode.getIdElm();
        LongBinaryOperator updateFunction = updateFunctionCode.getUpdateFunction();
        LongBinaryOperator mergeLazyFunction = updateFunctionCode.getMergeLazyFunction();
        BiFunction<Long, Integer, Long> collapseUpdateFunction = updateFunctionCode.getCollapseUpdateFunction();
        long defaultLazyValue = updateFunctionCode.getDefaultLazyValue();
        return new LazySegmentTree(t, operator, idElm, updateFunction, mergeLazyFunction, collapseUpdateFunction, defaultLazyValue);
    }
}

class LongQueue {
    private long[] a;
    private int head = 0, tail = 0;

    public LongQueue(int max) {
        a=new long[max+2];
    }
    public void addLast(long x) {
        a[tail++]=x;
    }
    public long pollFirst(){
        if (tail == head) {
            try { throw new Exception("no elements."); } 
            catch (Exception e) { e.printStackTrace(); }
        }
        return a[head++];
    }
    public long pollLast() {
        if (tail == head) {
            try { throw new Exception("no elements."); }
            catch (Exception e) { e.printStackTrace(); }
        }
        return a[--tail];
    }
    public long getFirst() {
        return a[head];
    }
    public long getLast() {
        return a[tail - 1];
    }
    public int size() {
        return tail - head;
    }
    public void init() {
        head = tail = 0;
    }
}


class LongUtil {
    public static long min(long... a) {
        long ret = Const.LINF;
        for (long c : a) ret = Math.min(ret, c);
        return ret;
    }

    public static long max(long... a) {
        long ret = -Const.LINF;
        for (long c : a) ret = Math.max(ret, c);
        return ret;
    }

    /**
     * Caluculate the ceil of a/b. Returns the smallest integer greater than or
     * equal to a/b while 'a/b' rounds fractional parts to ZERO.
     * 
     * @param a
     * @param b
     * @return the smallest integer greater than or equal to a/b
     */
    public static long cld(long a, long b) {
        if (a > 0 && b > 0) return (a + b - 1) / b;
        else if (a < 0 && b < 0) return (a + b + 1) / b;
        else return a / b;
    }

    /**
     * Caluculate the floor of a/b. Returns the largest integer less than or equal
     * to a/b while 'a/b' rounds fractional parts to ZERO.
     * 
     * @param a
     * @param b
     * @return the largest integer less than or equal to a/b
     */
    public static long fld(long a, long b) {
        if (a <= 0 && b > 0) return (a - b + 1) / b;
        else if (a > 0 && b <= 0) return (a - b - 1) / b;
        else return a / b;
    }

    public static long fold(LongBinaryOperator func, long a, long... b) {
        long ret = a;
        for (long c : b) ret = func.applyAsLong(ret, c);
        return ret;
    }
}


class MathUtil{
    /**
     * Enumarate primes equal to or less than n.
     * @param n
     * @return {@code ArrayList} that holds primes.
     */
    public static ArrayList<Integer> eratosthenes(int n) {
        int[] div = eratosthenesDivisors(n);
        ArrayList<Integer> result = new ArrayList<>();
        for (int i = 2; i <= n; i++) if (div[i] == i) result.add(i);
        return result;
    }
    /**
     * execute eratosthenes's prime-enumerate algorithm. a[i] holds the greatest
     * divisor of i. if a[i] = i, i is a prime number. This arrary enables you to
     * prime-factorize in O(log n) time.
     * @param n
     * @return divisor array.
     */
    public static int[] eratosthenesDivisors(int n) {
        int[] divisors = new int[n + 1];
        if (n <= 0) return null;
        for (int i = 1; i <= n; i++) {
            if ((i & 1) != 0) divisors[i] = i;
            else divisors[i] = 2;
        }
        for (int i = 3; i <= n; i += 2) {
            if (divisors[i] == i) {
                for (long j = (long) i * i; j <= n; j += i << 1) divisors[(int) j] = i;
            }
        }
        return divisors;
    }

    /**
     * Caluculate prime-factorization in O(sqrt(n)) time.
     * @param n
     * @return {@code HashMap} of {prime: index}
     */
    public static HashMap<Long, Integer> primeFactorization(long n) {
        HashMap<Long, Integer> primes = new HashMap<>();
        for (long p = 2; p * p <= n; p++) {
            int q = 0;
            while (n % p == 0) {
                n /= p;
                q++;
            }
            if (q > 0) primes.put(p, q);
        }
        if (n > 1) primes.put(n, 1);
        return primes;
    }

    private static HashMap<Long, Integer> lcm(HashMap<Long, Integer> amap, HashMap<Long, Integer> bmap) {
        if (amap.size() < bmap.size()) return lcm(bmap, amap);
        HashMap<Long, Integer> lcm = amap;
        for (Map.Entry<Long, Integer> e : bmap.entrySet()) {
            long prime = e.getKey();
            if (lcm.containsKey(prime)) lcm.put(prime, Math.max(lcm.get(prime), e.getValue()));
            else lcm.put(prime, e.getValue());
        }
        return lcm;
    }
    private static HashMap<Long, Integer> lcm(HashMap<Long, Integer> amap, long b) {
        HashMap<Long, Integer> bmap = primeFactorization(b);
        return lcm(amap, bmap);
    }
    public static HashMap<Long, Integer> lcm(long... a) {
        HashMap<Long, Integer> amap = new HashMap<>();
        for (long c : a) amap = lcm(amap, c);
        return amap;
    }
    public static long unsafeLCM(long a, long b) {
        return a * b / gcd(a, b);
    }

    /**
     * Caluculate the GCD of (a, b)/
     * 
     * @param a first value
     * @param b second value
     * @return GCD(a, b)
     */
    public static long gcd(long a, long b) {
        if (a < b) return gcd(b, a);
        if (b == 0) return a;
        if (a == 0) return b;
        long r = a % b;
        while (r != 0) {
            a = b;
            b = r;
            r = a % b;
        }
        return b;
    }
    public static long gcd(long... a){
        long gcd = 0;
        for (long c:a) gcd = gcd(gcd, c);
        return gcd;
    }
    /**
     * Return one of the solutions to {@code ax+by=gcd(a, b)}.
     * @return {@code x}, {@code y}, {@code gcd(a, b)}.
     * @param a a of ax+by=gcd(a, b).
     * @param b b of ax+by=gcd(a, b). class ReferenceLong is a reference type of long.
     */
    public static long[] extGCD(long a, long b) {
        ReferenceLong x = new ReferenceLong();
        ReferenceLong y = new ReferenceLong();
        long[] ret = new long[3];
        ret[2] = extGCD(a, b, x, y);
        ret[0] = x.v;
        ret[1] = y.v;
        return ret;
    }
    private static long extGCD(long a, long b, ReferenceLong x, ReferenceLong y) {
        if (b == 0) {
            x.v = 1;
            y.v = 0;
            return a;
        }
        long d = extGCD(b, a % b, y, x);
        y.v -= a / b * x.v;
        return d;
    }
    private static class ReferenceLong {
        long v = 0;
    }
}


class MinimumSpanningTree{
    public static Edge[] kruskal(int n, Edge[] edges){
        UnionFindTree t = new UnionFindTree(n);
        Queue<Edge> pq = new PriorityQueue<>((u, v) -> Long.compare(u.cost, v.cost));
        for(Edge e:edges) pq.add(e);
        Edge[] ret = new Edge[n-1];
        int index = 0;
        while(pq.size() > 0 && index < n){
            Edge e=pq.poll();
            if(!t.isSame(e.from, e.to)){
                t.unite(e.from, e.to);
                ret[index++]=e;
            }
        }
        return ret;
    }
    public static Edge[] prim(int n, Node[] nodes){
        HashSet<Integer> connected = new HashSet<>();
        connected.add(0);
        Queue<Edge> pq = new PriorityQueue<>((u, v) -> Long.compare(u.cost, v.cost));
        for(Edge e: nodes[0].edges) pq.add(e);
        Edge[] ret = new Edge[n-1];
        int index = 0; 
        while (pq.size() > 0 && connected.size() < n) {
            Edge e = pq.poll();
            for (int i = 0; i < 2; i++) {
                int v = i == 0 ? e.from : e.to;
                if (!connected.contains(v)) {
                    ret[index++] = e;
                    connected.add(v);
                    for(Edge edge: nodes[v].edges) {
                        if (!connected.contains(edge.from) || !connected.contains(edge.to)) pq.add(edge);
                    }
                }
            }
        }
        return ret;
    }
}

class ModUtil{
    public static long mul(long... a) {
        long ret = 1;
        for (long c : a) ret = (ret * c) % Const.MOD;
        return ret;
    }
    public static long div(long a, long... b) {
        long ret = a;
        for (long c : b) ret = (ret * inv(c)) % Const.MOD;
        return ret;
    }
    /**
     * Caluculate the value b s.t. a*b mod Const.MOD = 1.
     * @param a
     * @return inverse of a
     */
    public static long inv(long a) {
        long b = Const.MOD;
        long u = 1, v = 0;
        while (b >= 1) {
            long t = a / b;
            a -= t * b;
            long tmp1 = a; a = b; b = tmp1;
            u -= t * v;
            long tmp2 = u; u = v; v = tmp2;
        }
        u %= Const.MOD;
        return u >= 0 ? u : u + Const.MOD;
    }
    /**
     * Caluculate the combination nCr.
     * @param n left
     * @param r right
     * @return nCr
     */
    public static long comb(long n, long r) {
        if (n < r) return 0;
        r = Math.min(r, n - r);
        long res = 1;
        for (long d = 1; d <= r; d++) res = div(mul(res, n--), d);
        return res;
    }
    public static long[] fact(int n){
        long[] fact = new long[n+1];
        for (int i = 0; i <= n; i++) {
            if (i <= 1) fact[i] = 1;
            else fact[i] = mul(fact[i-1], i);
        }
        return fact;
    }
    public static long[] powarr(long a, int n){
        long[] ret = new long[n + 1];
        for(int i = 0; i <= n; i++) {
            if (i == 0) ret[i] = 1;
            else ret[i] = mul(ret[i - 1], a);
        }
        return ret;
    }
}


class Node{
    public int id;
    public ArrayList<Edge> edges;
    public long w;
    public int in;
    
    public Node(int id){
        this.id=id;
        this.edges = new ArrayList<Edge>();
    }
    public Node(int id, long w){
        this.id = id;
        this.w = w;
        this.edges = new ArrayList<>();
    }
    @Override public boolean equals(Object o){
        if(this == o) return true;
        if(! (o instanceof Node)) return false;
        Node n=(Node) o;
        return n.id == id;
    }
    @Override public int hashCode(){
        return id;
    }
}


@SuppressWarnings("unchecked")
class PolyLazySegmentTree<T, U>{
    private T[] tree;
    private U[] lazy;
    private T idElm;
    private U defaultLazyValue;
    private BiFunction<T, T, T> operator;
    private BiFunction<T, U, T> updateFunction;
    private BiFunction<U, U, U> mergeLazyFunction;
    private BiFunction<U, Integer, U> collapseUpdateFunction;
    private int size;
    private int leafs;
    private int height;
    private int baseOfLeaf;

    public PolyLazySegmentTree(T[] t, BiFunction<T, T, T> operator, T idElm, BiFunction<T, U, T> updateFunction, BiFunction<U, U, U> mergeLazyFunction , BiFunction<U, Integer, U> collapseUpdateFunction, U defaultLazyValue){
        int n = t.length;
        this.operator = operator;
        this.idElm = idElm;
        this.updateFunction = updateFunction;
        this.mergeLazyFunction = mergeLazyFunction;
        this.collapseUpdateFunction = collapseUpdateFunction;
        this.defaultLazyValue = defaultLazyValue;
        this.height = minimumPowerOfTwo(n);
        this.leafs = 1 << this.height;
        this.baseOfLeaf = this.leafs - 1;
        this.size = 2 * this.leafs - 1;
        this.lazy = (U[]) new Object[this.size];
        this.tree = (T[]) new Object[this.size];
        for(int i = size - 1; i >= 0; i--) {
            if(i >= baseOfLeaf + n) {
                this.tree[i] = this.idElm;
            } else if(isLeaf(i)) {
                this.tree[i] = t[i - baseOfLeaf];
            } else{
                this.tree[i] = operator.apply(this.tree[left(i)], this.tree[right(i)]);
            }
        }
    }

    public void applyForSegment(int l, int r, U v){
        applyForSegment(new Range(l, r), 0, new Range(0, leafs), v);
    }
    private T applyForSegment(Range queryRange, int k, Range treeRange, U v){
        evaluate(k, treeRange);
        if(queryRange.crosses(treeRange)) {
            if(queryRange.contains(treeRange)) {
                lazy[k] = mergeLazyFunction.apply(lazy[k], v);
                return updateFunction.apply(tree[k], collapseUpdateFunction.apply(lazy[k], treeRange.length()));
            } else {
                T left = applyForSegment(queryRange, left(k), treeRange.leftHalf(), v);
                T right = applyForSegment(queryRange, right(k), treeRange.rightHalf(), v);
                return tree[k] = operator.apply(left, right);
            }
        } else{
            return tree[k];
        }
    }
    public void applyForPoint(int i, U v){
        tree[baseOfLeaf + i] = updateFunction.apply(tree[baseOfLeaf + i], collapseUpdateFunction.apply(v, 1));
    }

    public T query(int l, int r){
        return query(new Range(l, r), 0, new Range(0, leafs));
    }
    private T query(Range queryRange, int k, Range treeRange){
        evaluate(k, treeRange);
        if(!queryRange.crosses(treeRange)){
            return idElm;
        } else if(queryRange.contains(treeRange)){
            return tree[k];
        } else{
            T left = query(queryRange, left(k), treeRange.leftHalf());
            T right = query(queryRange, right(k), treeRange.rightHalf());
            return operator.apply(left, right);
        }
    }
    private void evaluate(int k, Range r){
        if(lazy[k] != defaultLazyValue) {
            if(!isLeaf(k)){
                lazy[left(k)] = mergeLazyFunction.apply(lazy[left(k)], lazy[k]);
                lazy[right(k)] = mergeLazyFunction.apply(lazy[right(k)], lazy[k]);
            }
            tree[k] = updateFunction.apply(tree[k], collapseUpdateFunction.apply(lazy[k], r.length()));
            lazy[k] = defaultLazyValue;
        }
    }
    private int minimumPowerOfTwo(int n){
        int i = 0;
        while(1 << ++i < n);
        return i;
    }
    private boolean isLeaf(int i){
        return i >= baseOfLeaf;
    }
    private int left(int k){
        return 2 * k + 1;
    }
    private int right(int k){
        return 2 * k + 2;
    }

    public String toString(){
        StringBuilder sb = new StringBuilder();
        for(int h = 0; h <= height; h++) {
            for(int i = (1 << h) - 1; i < (1 << (h + 1)) - 1; i++) {
                sb.append(tree[i]).append(" ");
            }
            sb.append('\n');
        }
        return sb.toString();
    }
}


class Range{
    public static final int MAX = +Const.IINF;
    public static final int MIN = -Const.IINF;
    public static final Range EMPTY = new Range(MAX, MAX);
    public static final Range WHOLE = new Range(MIN, MAX);

    public int left;
    public int right;

    public Range(int left, int right){
        if(left >= right){
            this.left = EMPTY.left;
            this.right = EMPTY.right;
        } else{
            this.left = left;
            this.right = right;
        }
    }
    public boolean crosses(Range r){
        return this.left < r.right && r.left < this.right;
    }
    public boolean contains(Range r){
        if(this.isEmpty()) return false;
        if(r.isEmpty()) return true;
        return this.left <= r.left && r.right <= this.right;
    }
    public Range leftHalf(){
        if(this.isEmpty()) return EMPTY;
        return new Range(left, (left + right) >> 1);
    }
    public Range rightHalf(){
        if(this.isEmpty()) return EMPTY;
        return new Range((left + right) >> 1, right);
    }
    public int length(){
        return right - left;
    }
    public Range intersection(Range r){
        if(!this.crosses(r)) return EMPTY;
        return new Range(Math.max(this.left, r.left), Math.min(this.right, r.right));
    }
    public ArrayList<Range> union(Range r){
        ArrayList<Range> union = new ArrayList<>();
        if(this.isEmpty()){
            union.add(r); 
        } else if(r.isEmpty()){
            union.add(this);
        } else if(this.crosses(r)){
            union.add(new Range(Math.min(this.left, r.left), Math.max(this.right, r.right)));
        } else {
            if(this.left < r.left){
                union.add(this);
                union.add(r);
            } else{
                union.add(r);
                union.add(this);
            }
        }
        return union;
    }
    public boolean isEmpty(){
        return this.equals(EMPTY);
    }
    public boolean nonEmpty(){
        return !this.isEmpty();
    }

    public static boolean crosses(Range r1, Range r2){
        return r1.crosses(r2);
    }
    public static Range leftHalf(Range r){
        return r.leftHalf();
    }
    public static Range rightHalf(Range r){
        return r.rightHalf();
    }
    public static int length(Range r){
        return r.length();
    }
    public static Range interSection(Range... rs){
        Range ret = WHOLE;
        for(Range r: rs) ret = ret.intersection(r);
        return ret;
    }
    public static ArrayList<Range> union(Range... rs){
        sort(rs, (u, v) -> Integer.compare(u.left, v.left));
        ArrayList<Range> union = new ArrayList<>();
        Range now = null;
        for(Range r: rs){
            if(r.isEmpty()) break;
            if(isNull(now)){
                now = r;
            } else{
                if(r.left <= now.right){
                    now.right = r.right;
                } else{
                    union.add(now);
                    now = r;
                }
            }
        }
        if(!isNull(now) && !now.equals(EMPTY)) union.add(now);
        if(union.isEmpty()) union.add(EMPTY);
        return union;
    }
    public static boolean isEmpty(Range r){
        return r.isEmpty();
    }
    public static boolean nonEmpty(Range r){
        return r.nonEmpty();
    }

    @Override
    public boolean equals(Object o){
        if(this == o) return true;
        if(!(o instanceof Range)) return false;
        Range r = (Range) o;
        return this.left == r.left && this.right == r.right; 
    }
    @Override
    public int hashCode(){
        return hash(left, right);
    }
    @Override
    public String toString(){
        return "["+left+", "+right+")";
    }
}


class RollingHash {
    private static final long mod = (1l << 61) - 1;
    private static final long mask31 = (1l << 31) - 1;
    private static final long mask30 = (1l << 30) - 1;
    private long base;
    private long[] pow;
    private int length;
    private long[] hash; // hash[i] is the hash of substring[0, i). (i = 0, 1, ..., length)

    public RollingHash(char[] ch) {
        this.length = ch.length;
        Random r = new Random(System.currentTimeMillis());
        do this.base = r.nextLong(); while (this.base >= mod - 1 || this.base <= 6000);
        this.pow = new long[this.length + 1];
        for (int i = 0; i <= this.length; i++) {
            if (i == 0) this.pow[i] = 1;
            else this.pow[i] = mod(mul(this.pow[i - 1], this.base));
        }
        this.hash = new long[this.length + 1];
        for(int i = 0; i < this.length; i++) this.hash[i + 1] = mod(mul(this.hash[i], this.base) + ch[i] + 1);
    }
    public long hash(int begin, int end) {
        long ret = hash[end] - mod(mul(hash[begin], pow[end - begin]));
        if (ret < 0) ret += mod;
        return ret;
    }

    // calc a*b mod 2^61-1 without overflow using the fact that 2^61 = 1 mod 2^61-1.
    private long mul(long a, long b) {
        // au is upper 30(=61-31) bits of a, ad is lower 31 bits of a.
        // bu is upper 30(=61-31) bits of b, bd is lower 31 bits of b.
        // => a*b = (au*2^31 + ad)*(bu*2^31 + bd) = au*bu*2^62 + (au*bd + ad*bu)*2^31 + ad*bd.
        long au = a >> 31, ad = a & mask31;
        long bu = b >> 31, bd = b & mask31;
        // 1. au*bu*2^62 equiv to au*bu*2 <= 2*(2^30-1)*(2^30-1)
        // 2. m := au*bd + ad*bu <= 2*(2^30-1)*(2^31-1)
        // mu is upper 31(=61-30) bits of m, md is lower 30 bits of m.
        // m*2^31 = midu*2^61 + midd*2^31 = midu + midd*2^31 <= 2^61+2^31
        // 3. ad*bd <= (2^31-1)*(2^31-1)
        // => (au*bu*2)+(mu+md*2^31)+(ad*bd) < L_MAX
        long m = au * bd + ad * bu;
        long mu = m >> 30, md = m & mask30;
        return ((au * bu) << 1) + (mu + (md << 31)) + (ad * bd);
    }
    private long mod(long l) {
        l = (l & mod) + (l >> 61);
        while (l > mod) l -= mod;
        return l;
    }
}


class Search {
    // return the distance from 's' to other vertices as an array.
    public static int[] bfs(ArrayList<Integer>[] nodes, int s) {
        IntQueue q = new IntQueue(nodes.length);
        q.addLast(s);
        int n = nodes.length;
        int[] d = new int[n];
        fill(d, -1);
        d[s] = 0;
        while(q.size() > 0){
            int now = q.pollFirst();
            for(int next: nodes[now]){
                if(d[next] < 0){
                    d[next] = d[now] + 1;
                    q.addLast(next);
                }
            }
        }
        return d;
    }

    /** 
     * return the shortest path from 's' to 't' as an array.
     * [s, a1, a2, ..., ak, t] => distance = array.length-1
     * if NO path from 's' to 't' exists, returns NULL.
     */
    public static int[] bfs(ArrayList<Integer>[] nodes, int s, int t) {
        IntQueue q = new IntQueue(nodes.length + 1);
        q.addLast(s);
        int n = nodes.length;
        int[] d = new int[n];
        int[] prev = new int[n];
        fill(d, -1);
        d[s] = 0;
        while(q.size() > 0){
            int now = q.pollFirst();
            for(int next: nodes[now]){
                if(d[next] < 0){
                    d[next] = d[now] + 1;
                    prev[next] = now;
                    q.addLast(next);
                }
            }
        }
        if(d[t] < 0) return null;
        int now = t;
        int[] path = new int[d[t] + 1];
        for (int i = 0; i <= d[t]; i++) {
            path[d[t] - i] = now;
            now = prev[now];
        }
        return path;
    }

    public static int[] _01bfs(Node[] nodes, int s){
        ArrayDeque<Integer> dq = new ArrayDeque<>();
        dq.add(s);
        int n = nodes.length;
        int[] d = new int[n];
        boolean[] visited=new boolean[n];
        fill(d, Const.IINF);
        d[s] = 0;
        while (dq.size() > 0) {
            int now = dq.pollFirst();
            if(visited[now]) continue;
            visited[now] = true;
            for (Edge e: nodes[now].edges) {
                int next = e.to;
                int cost = (int) e.cost;
                if (d[next] > d[now]) {
                    if (cost == 0) dq.addFirst(next);
                    else dq.addLast(next);
                    d[next] = d[now] + cost;
                }
            }
        }
        return d;
    }
}


class SegmentTree{
    private long[] tree;
    private long idElm;
    private LongBinaryOperator operator;
    private int size;
    private int leafs;
    private int height;
    private int baseOfLeaf;

    public SegmentTree(long[] t, long idElm, LongBinaryOperator operator){
        int n = t.length;
        this.idElm = idElm;
        this.height = minimumPowerOfTwo(n);
        this.leafs = 1 << this.height;
        this.baseOfLeaf = this.leafs - 1;
        this.size = 2 * this.leafs - 1;
        this.tree = new long[this.size];
        for(int i = size - 1; i >= 0; i--) {
            if(i >= baseOfLeaf + n) this.tree[i] = this.idElm;
            else if(isLeaf(i)) this.tree[i] = t[i - baseOfLeaf];
            else this.tree[i] = operator.applyAsLong(this.tree[left(i)], this.tree[right(i)]);
        }
    }
    public void update(int i, int v){
        int index = i + baseOfLeaf;
        int parent = index;
        tree[index] = v;
        while(parent > 0){
            parent = (parent - 1) >> 1;
            tree[parent] = operator.applyAsLong(tree[left(parent)], tree[right(parent)]);
        }
    }
    public long query(int a, int b){
        return query(new Range(a, b), 0, new Range(0, leafs));
    }
    private long query(Range queryRange, int k, Range treeRange){
        if(!queryRange.crosses(treeRange)){
            return idElm;
        } else if(queryRange.contains(treeRange)){
            if(isLeaf(k)) return tree[k];
            else return tree[k] = operator.applyAsLong(tree[left(k)], tree[right(k)]);
        } else{
            long left=query(queryRange, left(k), treeRange.leftHalf());
            long right=query(queryRange, right(k), treeRange.rightHalf());
            return operator.applyAsLong(left, right);
        }
    }
    private int minimumPowerOfTwo(int n){
        int i = 0;
        while(1 << ++i < n);
        return i;
    }
    private boolean isLeaf(int i){
        return i >= baseOfLeaf;
    }
    private int left(int k){
        return 2 * k + 1;
    }
    private int right(int k){
        return 2 * k + 2;
    }
    public String toString(){
        StringBuilder sb = new StringBuilder();
        for(int h = 0; h <= height; h++){
            for(int i = (1 << h) - 1; i < (1 << (h + 1)) - 1; i++){
                sb.append(tree[i]).append(' ');
            }
            sb.append('\n');
        }
        return sb.toString();
    }
}

class TopologicalSort{
    public static int[] topologicalSort(Node[] nodes){
        int n = nodes.length;
        int[] ret = new int[n];
        IntQueue zeros = new IntQueue(n);
        for(Node node: nodes) if(node.in == 0) zeros.addLast(node.id);
        int index = 0;
        while(zeros.size() > 0){
            int v = zeros.pollFirst();
            for (Edge e: nodes[v].edges) if(--nodes[e.to].in == 0) zeros.addLast(e.to);
            ret[index++]=v;
        }
        if(index < n) return null;
        return ret;
    }
    
    // for example (n=9)
    // [1, 8] -> [2, 5, 6] -> [3, 7] -> [4] -> [9]
    // => length:5
    public static int shortest(Node[] nodes){
        int n = nodes.length;
        int ret = 0;
        IntQueue zeros = new IntQueue(n);
        for(Node node: nodes) if(node.in == 0) zeros.addLast(node.id);
        int num = zeros.size();
        while(zeros.size() > 0){
            int size = zeros.size();
            while(size > 0){
                int v = zeros.pollFirst();
                size--;
                for(Edge e: nodes[v].edges){
                    if(--nodes[e.to].in == 0){
                        zeros.addLast(e.to);
                        num++;
                    }
                }
            }
            ret++;
        }
        if(num < n) return -1;
        return ret;
    }
}


class UnionFindTree {
    private int[] parent;
    private int[] rank;
    private int[] size;
    private int groups;
    public UnionFindTree(int n){
        this.parent = new int[n];
        this.rank = new int[n];
        this.size = new int[n];
        this.groups = n;
        fill(this.size, 1);
        for(int i = 0; i < n; i++) parent[i] = i;
    }
    public int root(int x){
        if(parent[x] == x) return x;
        return parent[x] = root(parent[x]);
    }
    public boolean isSame(int x, int y){
        return root(x) == root(y);
    }
    public void unite(int x, int y){
        int xr = root(x);
        int yr = root(y);
        if(xr == yr) return;
        if(rank[xr] < rank[yr]){
            parent[xr] = yr;
            size[yr] += size[xr];
        }
        else{
            parent[yr] = xr;
            size[xr] += size[yr];
            if(rank[xr] == rank[yr]) rank[xr]++;
        }
        groups--;
    }
    public int size(int x){
        return size[root(x)];
    }
    public int groups(){
        return groups;
    }
}
