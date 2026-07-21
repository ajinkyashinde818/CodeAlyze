using System;
using System.Linq;
using System.Collections.Generic;
using Debug = System.Diagnostics.Debug;
using StringBuilder = System.Text.StringBuilder;
//using System.Numerics;
//using Point = System.Numerics.Complex;
using Number = System.Int64;
namespace Program
{
    public class Solver
    {
        public void Solve()
        {
            var n = sc.Integer();
            var T = new HLTreeGraph(n);
            var G = Enumerate(n, x => new List<KeyValuePair<int, long>>());
            var dist = new long[n];
            T.dist = dist;
            for (int i = 1; i < n; i++)
            {
                var p = sc.Integer() - 1;
                var d = sc.Integer();
                T.AddEdge(p, i, d);
                G[p].Add(new KeyValuePair<int, Number>(i, d));
            }
            T.Build(0);
            var k = 0L;
            var sum = 0L;
            Func<int, long> f = v =>
                {
                    if (v == -1) return 1L << 60;
                    var ret = sum + k * dist[v];
                    ret += T.Query(v);
                    return ret;
                };
            Func<int, int, KeyValuePair<int, long>> g = (v, p) =>
                  {
                      var l = T.d[p] - 1; var r = T.d[v];
                      while (l + 1 < r)
                      {
                          var m = (l + r) / 2;
                          var ll = f(T.Get(v, m)); var rr = f(T.Get(v, m + 1));
                          if (ll < rr) r = m;
                          else l = m;
                      }
                      v = T.Get(v, r);
                      return new KeyValuePair<int, Number>(v, f(v));
                  };
            var c = 0;


            for (int i = 0; i < n; i++)
            {
                k++;
                sum += dist[i];
                T.Update(i);

                var lca = T.GetLCA(c, i);
                var x = g(c, lca);
                var y = g(i, lca);
                var z = -1L;
                if (x.Value <= y.Value)
                { c = x.Key; z = x.Value; }
                else { c = y.Key; z = y.Value; }
                IO.Printer.Out.WriteLine(z);
            }
        }

        public IO.StreamScanner sc = new IO.StreamScanner(Console.OpenStandardInput());
        static T[] Enumerate<T>(int n, Func<int, T> f) { var a = new T[n]; for (int i = 0; i < n; ++i) a[i] = f(i); return a; }
        static public void Swap<T>(ref T a, ref T b) { var tmp = a; a = b; b = tmp; }
    }
}

#region main
static class Ex
{
    //static public string AsString(this IEnumerable<char> ie) { return new string(System.Linq.Enumerable.ToArray(ie)); }
    //static public string AsJoinedString<T>(this IEnumerable<T> ie, string st = " ") { return string.Join(st, ie); }
    static public void Main()
    {
        var solver = new Program.Solver();
        solver.Solve();
        Program.IO.Printer.Out.Flush();
    }
}
#endregion
#region Ex
namespace Program.IO
{
    using System.IO;
    using System.Text;
    using System.Globalization;
    public class Printer: StreamWriter
    {
        static Printer() { Out = new Printer(Console.OpenStandardOutput()) { AutoFlush = false }; }
        public static Printer Out { get; set; }
        public override IFormatProvider FormatProvider { get { return CultureInfo.InvariantCulture; } }
        public Printer(System.IO.Stream stream) : base(stream, new UTF8Encoding(false, true)) { }
        public Printer(System.IO.Stream stream, Encoding encoding) : base(stream, encoding) { }
        public void Write<T>(string format, T[] source) { base.Write(format, source.OfType<object>().ToArray()); }
        public void WriteLine<T>(string format, T[] source) { base.WriteLine(format, source.OfType<object>().ToArray()); }
    }
    public class StreamScanner
    {
        public StreamScanner(Stream stream) { str = stream; }
        public readonly Stream str;
        private readonly byte[] buf = new byte[1024];
        private int len, ptr;
        public bool isEof = false;
        public bool IsEndOfStream { get { return isEof; } }
        private byte read()
        {
            if (isEof) return 0;
            if (ptr >= len) { ptr = 0; if ((len = str.Read(buf, 0, 1024)) <= 0) { isEof = true; return 0; } }
            return buf[ptr++];
        }
        public char Char() { byte b = 0; do b = read(); while ((b < 33 || 126 < b) && !isEof); return (char)b; }

        public string Scan()
        {
            var sb = new StringBuilder();
            for (var b = Char(); b >= 33 && b <= 126; b = (char)read())
                sb.Append(b);
            return sb.ToString();
        }
        public string ScanLine()
        {
            var sb = new StringBuilder();
            for (var b = Char(); b != '\n'; b = (char)read())
                if (b == 0) break;
                else if (b != '\r') sb.Append(b);
            return sb.ToString();
        }
        public long Long()
        {
            if (isEof) return long.MinValue;
            long ret = 0; byte b = 0; var ng = false;
            do b = read();
            while (b != 0 && b != '-' && (b < '0' || '9' < b));
            if (b == 0) return long.MinValue;
            if (b == '-') { ng = true; b = read(); }
            for (; true; b = read())
            {
                if (b < '0' || '9' < b)
                    return ng ? -ret : ret;
                else ret = ret * 10 + b - '0';
            }
        }
        public int Integer() { return (isEof) ? int.MinValue : (int)Long(); }
        public double Double() { var s = Scan(); return s != "" ? double.Parse(s, CultureInfo.InvariantCulture) : double.NaN; }
        private T[] enumerate<T>(int n, Func<T> f)
        {
            var a = new T[n];
            for (int i = 0; i < n; ++i) a[i] = f();
            return a;
        }

        public char[] Char(int n) { return enumerate(n, Char); }
        public string[] Scan(int n) { return enumerate(n, Scan); }
        public double[] Double(int n) { return enumerate(n, Double); }
        public int[] Integer(int n) { return enumerate(n, Integer); }
        public long[] Long(int n) { return enumerate(n, Long); }
    }
}
#endregion

#region Edge
public struct Edge
{
    public int from, to, cost;
    public long add;
    public Edge(int f, int t, int x) : this() { from = f; to = t; cost = x; }
}
#endregion
#region HLTreeGraph

public class HLTreeGraph
{
    public long[] dist;
    /// <summary>
    /// ????´??????????????????°
    /// </summary>
    int N;
    /// <summary>
    /// ????´?????????°??????
    /// </summary>
    List<Edge>[] G;
    /// <summary>
    /// ?????§???????????????
    /// </summary>
    List<Chain> H = new List<Chain>();

    int[] subTreeSize;
    int[] par;
    int[] pos;

    /// <summary>
    /// ????????¨????????±???
    /// </summary>
    public int[] d;


    /// <summary>
    ///u????±????????????§??????
    /// </summary>
    Chain[] go;
    public HLTreeGraph(int n)
    {
        N = n;
        G = Enumerate(n, x => new List<Edge>());
        subTreeSize = new int[n];
        pos = new int[n];
        d = new int[n];
        par = new int[n];
        go = new Chain[n];
    }
    public void AddEdge(int f, int t, int x)
    {
        G[f].Add(new Edge(f, t, x));
        G[t].Add(new Edge(t, f, x));
    }
    #region impl
    public void Build(int root)
    {
        ComputeSubTreeSize(root);
        Decomposite(new Edge(-1, root, 0), -1, 0);
    }
    public void ComputeSubTreeSize(int root)
    {
        const long X = 1000000000;
        var stack = new FastStack<long>(N + 1);
        stack.Push(root * X);
        par[root] = -1;
        d[root] = 0;
        dist[root] = 0;
        while (stack.Any())
        {
            var val = stack.Peek();
            var u = (int)(val / X);
            var it = (int)(val % X);

            if (it == G[u].Count)
            {
                stack.Pop();
                subTreeSize[u]++;
                if (par[u] >= 0) subTreeSize[par[u]] += subTreeSize[u];
            }
            else
            {
                var to = G[u][it].to;
                stack.Last++;
                if (to == par[u]) continue;

                par[to] = u;
                d[to] = d[u] + 1;
                dist[to] = dist[u] + G[u][it].cost;
                stack.Push(to * X);
            }
        }

    }
    public void Decomposite(Edge light, int prevId, int lv)
    {
        var chain = new Chain() { light = light, id = H.Count, parId = prevId, level = lv };
        H.Add(chain);
        var prev = light.from;
        var cur = light.to;
        while (cur != prev)
        {
            var next = cur;
            var max = 0;
            go[cur] = chain;
            pos[cur] = chain.heavy.Count;
            foreach (var to in G[cur])
            {
                var t = to.to;
                if (t != prev) max = Math.Max(max, subTreeSize[t]);
            }
            foreach (var to in G[cur])
            {
                var t = to.to;
                if (t == prev) continue;
                if (max == subTreeSize[t])
                {
                    //Debug.WriteLine("{0}->{1}", cur, t);
                    max = 1 << 30;
                    next = t;
                    chain.heavy.Add(to);
                }
                else Decomposite(to, chain.id, lv + 1);
            }
            prev = cur;
            cur = next;
        }
        chain.init(this);

    }
    #endregion

    public void Update(int v)
    {
        while (v != -1)
        {
            go[v].sub.Add(pos[v] + 1, -2 * dist[v]);
            go[v].coef.Add(1, -2); go[v].coef.Add(pos[v] + 1, 2);
            if (go[v].light.from != -1)
                go[v].light.add += 2 * dist[go[v].light.from];
            v = go[v].light.from;
        }
    }
    /// <summary>
    /// (u,v)?????¢???????????¨??????????????????
    /// </summary>
    public long Query(int v)
    {
        long ans = 0;
        while (v != -1)
        {
            ans += go[v].coef[pos[v] + 1] * dist[v];
            ans += go[v].sub[pos[v] + 1];
            if (go[v].light.from != -1)
                ans += go[v].light.add;
            v = go[v].light.from;
        }
        return ans;
    }
    public int Get(int v, int x)
    {
        if (x < 0) return -1;
        if (d[v] < x) return -1;
        for (;;)
        {
            var p = go[v].light.to;
            if (d[p] == x) return p;
            else if (d[p] < x)
                return go[v].heavy[x - d[p] - 1].to;
            v = go[v].light.from;
        }
    }
    /// <summary>
    /// LCA(u,v)?????????
    /// </summary>
    public int GetLCA(int u, int v)
    {
        while (go[u].id != go[v].id)
        {
            if (go[u].level < go[v].level) v = go[v].light.from;
            else u = go[u].light.from;
        }
        if (d[u] <= d[v]) return u;
        else return v;
    }

    static T[] Enumerate<T>(int n, Func<int, T> f) { var a = new T[n]; for (int i = 0; i < n; ++i) a[i] = f(i); return a; }

}
public class Chain
{
    /// <summary>
    /// light edge
    /// </summary>
    public Edge light;
    /// <summary>
    /// heavy edge?????????
    /// </summary>
    public List<Edge> heavy = new List<Edge>();
    /// <summary>
    /// ???????????§???????????????
    /// </summary>
    public int parId;
    /// <summary>
    /// ????´?????????¨??§?????±???
    /// </summary>
    public int level;
    public int id;
    public FenwickTree coef;
    public FenwickTree sub;
    public void init(HLTreeGraph G)
    {
        coef = new FenwickTree(heavy.Count + 2);
        sub = new FenwickTree(heavy.Count + 2);

    }

}
#endregion
#region FenwickTree
public class FenwickTree
{
    int n;
    Number[] bit;
    int max = 1;
    public FenwickTree(int size)
    {
        n = size; bit = new Number[n + 1];
        while ((max << 1) <= n) max <<= 1;
    }
    /// <summary>sum[a,b]</summary>
    public Number this[int i, int j] { get { return this[j] - this[i - 1]; } }
    /// <summary>sum[0,i]</summary>
    public Number this[int i] { get { Number s = 0; for (; i > 0; i -= i & -i) s += bit[i]; return s; } }
    public int LowerBound(Number w)
    {
        if (w <= 0) return 0;
        int x = 0;
        for (int k = max; k > 0; k >>= 1)
            if (x + k <= n && bit[x + k] < w)
            {
                w -= bit[x + k];
                x += k;
            }
        return x + 1;
    }
    /// <summary>add v to bit[i]</summary>
    public void Add(int i, Number v)
    {
        if (i == 0) System.Diagnostics.Debug.Fail("BIT is 1 indexed");
        for (; i <= n; i += i & -i) bit[i] += v;
    }
    public Number[] Items
    {
        get
        {
            var ret = new Number[n + 1];
            for (int i = 0; i < ret.Length; i++)
                ret[i] = this[i, i];
            return ret;
        }
    }
}
#endregion

#region Stack<T>
public class FastStack<T>
{
    T[] data;
    int ptr;
    public FastStack(int size) { data = new T[size]; }
    public void Push(T item) { data[ptr++] = item; }
    public T Pop() { return data[--ptr]; }
    public T Peek() { return data[ptr - 1]; }
    public bool Any() { return ptr != 0; }
    public T Last { get { return data[ptr - 1]; } set { data[ptr - 1] = value; } }
    public int Count { get { return ptr; } }
}
#endregion
