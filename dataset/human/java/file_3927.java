import java.io.*;
import java.util.*;
import java.util.function.*;

class Main
{
    public static void main(String[] args)
    {
        Graph g = Graph.readTree(true);
        
        Graph.Stack s = new Graph.Stack(g.size());
        long[] depth = new long[g.size()];
        
        g.dfs(0, r -> {
            depth[r.to] = r.dist;
            s.insert(new Graph.Reach(r.from, r.to, r.dist - depth[r.from]));
            return false;
        });
        
        long[] height = new long[g.size()];
        
        while (!s.isEmpty())
        {
            Graph.Reach r = s.drop();
            if (r.from != r.to)
                height[r.from] = Math.max(height[r.from], height[r.to] + r.dist);
        }
        
        long[] dp = new long[g.size()];
        
        g.dfs(0, r -> {
            Graph.Reach[] a = g.get(r.to).stream().filter( x -> x.to != r.from ).toArray(Graph.Reach[]::new);
            Arrays.sort(a, (i, j) -> Long.compare(height[j.to]+j.dist, height[i.to]+i.dist) );
            long h1 = a.length > 1 ? Math.max(dp[r.to], height[a[1].to]+a[1].dist) : dp[r.to];
            long h2 = a.length > 0 ? height[a[0].to]+a[0].dist : 0;
            long h3 = Math.max(h1, h2);
            for (Graph.Reach x : a)
                dp[x.to] = (x == a[0] ? h1 : h3) + x.dist;
            dp[r.to] = h3;
            return false;
        });
        
        for (long d : dp) System.out.println(d);
    }
}

class Graph extends ArrayList<ArrayList<Graph.Reach>>
{
    static Graph readTree() { return readTree(false); }
    static Graph readTree(boolean withDistance) { return readTree(new Scanner(System.in), withDistance); }
    static Graph readTree(Scanner in, boolean withDistance) { return readTree(in, in.nextInt(), withDistance); }
    static Graph readTree(Scanner in, int size, boolean withDistance)
    {
        Graph g = new Graph(size, false, withDistance);
        g.readEdges(in, size - 1);
        return g;
    }

    public Graph(int size, boolean direct, boolean withDistance)
    {
        super(size);
        for (int i = 0; i < size; i++) add(new ArrayList<>());
        this.direct = direct;
        this.withDistance = withDistance;
    }

    static class Reach
    {
        public int from, to;
        public long dist;
        Reach(int f, int t, long d) { from = f; to = t; dist = d; }
    }

    static interface Callback extends Function<Reach, Boolean> {}

    Reach dfs(int start, Callback callback)
    {
        final Stack stack = new Stack(size());
        return travel(stack, false, start, callback);
    }

    Reach bfs(int start, Callback callback)
    {
        final Queue queue = new Queue(size());
        return travel(queue, false, start, callback);
    }

    Reach dijkstra(int start, Callback callback)
    {
        final PQ pq = new PQ(size() * 3);
        return travel(pq, false, start, callback);
    }

    Reach dfs_inv(int start, Callback callback)
    {
        final Stack stack = new Stack(size());
        return travel(stack, true, start, callback);
    }

    Reach bfs_inv(int start, Callback callback)
    {
        final Queue queue = new Queue(size());
        return travel(queue, true, start, callback);
    }

    Reach dijkstra_inv(int start, Callback callback)
    {
        final PQ pq = new PQ(size() * 3);
        return travel(pq, true, start, callback);
    }

    boolean direct, withDistance;

    Reach addEdge(int from, int to) { return addEdge(from, to, 1); }
    Reach addEdge(int from, int to, long dist)
    {
        Reach ret;
        get(from).add(ret = new Reach(from, to, dist));
        get(to).add(new Reach(to, from, direct ? -dist : dist));
        return ret;
    }

    Reach readEdge(Scanner in)
    {
        int from = in.nextInt();
        int to = in.nextInt();
        long dist = withDistance ? in.nextLong() : 1L;
        return addEdge(from, to, dist);
    }

    void readEdges(Scanner in) { readEdges(in, in.nextInt()); }
    void readEdges(Scanner in, int numOfEdge)
    {
        while (numOfEdge-- > 0) readEdge(in);
    }

    static interface Collection
    {
        void insert(Reach e);
        Reach drop();
        boolean isEmpty();
        void clear();
    }

    static class Stack extends ArrayDeque<Reach> implements Collection
    {
        Stack(int size) { super(size); }
        public void insert(Reach e) { offerFirst(e); }
        public Reach drop() { return pollFirst(); }
    }

    static class Queue extends ArrayDeque<Reach> implements Collection
    {
        Queue(int size) { super(size); }
        public void insert(Reach e) { offerLast(e); }
        public Reach drop() { return pollFirst(); }
    }

    static class PQ extends PriorityQueue<Reach> implements Collection
    {
        PQ(int size) { super(size, (a, b) -> Long.compare(a.dist, b.dist) ); }
        public void insert(Reach e) { offer(e); }
        public Reach drop() { return poll(); }
    }
    
    Reach topological(boolean inv, Callback callback)
    {
        long c = inv ? -1L : 1L;
        final Queue que = new Queue(size());
        final int[] children = new int[size()];
        que.clear();
        Arrays.fill(children, 0);
        for (int i = 0; i < size(); i++)
        {
            for (Reach x : get(i))
            {
                if (c * x.dist < 0) children[i]++;
            }
            if (children[i] == 0)
                que.insert(new Reach(i, i, 0));
        }
        while (!que.isEmpty())
        {
            Reach current = que.drop();
            if (callback.apply(current)) return current;
            for (Reach x : get(current.to))
            {
                if (c * x.dist < 0) continue;
                if (--children[x.to] == 0)
                    que.insert(new Reach(current.to, x.to, current.dist + c * x.dist));
            }
        }
        return null;
    }

    Reach travel(Collection col, boolean inv, int start, Callback callback)
    {
        long c = inv ? -1L : 1L;
        final boolean[] visited = new boolean[size()];
        Arrays.fill(visited, false);
        visited[start] = true;
        col.clear();
        col.insert(new Reach(start, start, 0));
        for (int count = size(); !col.isEmpty() && count > 0; count--)
        {
            Reach current = col.drop();
            if (callback.apply(current)) return current;
            for (Reach x : get(current.to))
            {
                if (visited[x.to] || c * x.dist < 0 ) continue;
                visited[x.to] = true;
                col.insert(new Reach(current.to, x.to, current.dist + c * x.dist));
            }
        }
        return null;
    }
}
