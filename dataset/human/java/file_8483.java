import java.io.*;
import java.util.*;

/**
 * @author baito
 */
class UnionFindTree
{
    int[] par;
    int[] rank;
    int[] sizes;

    UnionFindTree(int n)
    {
        par = new int[n];
        rank = new int[n];
        sizes = new int[n];
        for (int i = 0; i < n; i++)
        {
            par[i] = i;
            sizes[i] = 1;
        }
    }

    int root(int x)
    {
        if (par[x] == x) return x;
        else return par[x] = root(par[x]);
    }

    void unite(int x, int y)
    {
        x = root(x);
        y = root(y);

        if (x == y) return;
        if (rank[x] < rank[y])
        {
            par[x] = y;
            sizes[y] += sizes[x];
        }
        else
        {
            par[y] = x;
            sizes[x] += sizes[y];
            if (rank[x] == rank[y]) rank[x]++;
        }
    }

    boolean isSame(int x, int y)
    {
        return root(x) == root(y);
    }

    int size(int x)
    {
        return sizes[par[x]];
    }
}

public class Main
{
    static StringBuilder sb = new StringBuilder();
    static Scanner sc = new Scanner(System.in);
    static int INF = 12345678;
    static long LINF = 123456789123456789L;
    static long MINF = -123456789123456789L;
    static long MOD = 1000000007;
    static int[] y4 = {0, 1, 0, -1};
    static int[] x4 = {1, 0, -1, 0};
    static int[] y8 = {0, 0, 1, 0, -1, -1, 1, 1, -1};
    static int[] x8 = {0, 1, 0, -1, 0, 1, -1, 1, -1};
    static long[] F;//factorial
    static boolean[] isPrime;
    static int[] primes;
    static char[][] map;

    static int N, K, L;
    static int[] A;


    public static void main(String[] args)
    {
        N = sc.nextInt();
        K = sc.nextInt();
        L = sc.nextInt();
        UnionFindTree u1 = new UnionFindTree(N);
        UnionFindTree u2 = new UnionFindTree(N);
        for (int i = 0; i < K; i++)
            u1.unite(sc.nextInt() - 1, sc.nextInt() - 1);
        for (int i = 0; i < L; i++)
            u2.unite(sc.nextInt() - 1, sc.nextInt() - 1);

        Map<Long, Integer> map = new HashMap<>();

        for (int i = 0; i < N; i++)
        {
            int r1 = u1.root(i);
            int r2 = u2.root(i);
            Long key = getHashKey(r1, r2);
            Integer v = map.get(key);
            map.put(key, v == null ? 1 : v + 1);
        }
        int[] cous = new int[N];
        for (int i = 0; i < N; i++)
        {
            int r1 = u1.root(i);
            int r2 = u2.root(i);
            Long key = getHashKey(r1, r2);
            System.out.println(map.get(key));
        }
    }

    public static long getHashKey(int a, int b)
    {
        return (long) a << 32 | b;
    }


}
