using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Diagnostics;

public class Program
{
    public static readonly int Mod = 1000000007;

    public static void Main(string[] args)
    {
        int R = Scanner.Int;
        int G = Scanner.Int;
        int B = Scanner.Int;
        int N = Scanner.Int;

        long pat = 0;
        foreach(int r in Enumerable.Range(0, (N / R) + 1))
        {
            int n = N - (R * r);
            foreach(int g in Enumerable.Range(0, (n / G) + 1))
            {
                int n2 = n - (G * g);
                if(n2 % B == 0) pat++;
            }
        }

        Console.WriteLine(pat);
        Console.ReadLine();
    }
}

/// <summary>
/// スキャナ
/// </summary>
public static class Scanner
{
    public static char[] separator = new char[] { ' ' };

    private static IEnumerator<string> enumerator = Enumerator();
    private static IEnumerator<string> Enumerator()
    {
        while (true)
        {
            foreach (string s in Console.ReadLine().Split(separator))
            {
                yield return s;
            }
        }
    }

    public static string[] StringArray(int N)
    {
        string[] ret = new string[N];
        for(int i = 0; i < N; i++)
        {
            ret[i] = Scanner.String;
        }
        return ret;
    }
    public static int[] IntArray(int N)
    {
        int[] ret = new int[N];
        for(int i = 0; i < N; i++)
        {
            ret[i] = Scanner.Int;
        }
        return ret;
    }
    public static long[] LongArray(int N)
    {
        long[] ret = new long[N];
        for(int i = 0; i < N; i++)
        {
            ret[i] = Scanner.Long;
        }
        return ret;
    }
    public static double[] DoubleArray(int N)
    {
        double[] ret = new double[N];
        for(int i = 0; i < N; i++)
        {
            ret[i] = Scanner.Double;
        }
        return ret;
    }
    public static char[] CharArray(int N)
    {
        char[] ret = new char[N];
        for(int i = 0; i < N; i++)
        {
            ret[i] = Scanner.Char;
        }
        return ret;
    }
    public static Tuple<int, int>[] IntTupleArray(int N)
    {
        Tuple<int, int>[] ret = new Tuple<int, int>[N];
        for(int i = 0; i < N; i++)
        {
            ret[i] = Scanner.IntTuple;
        }
        return ret;
    }
    public static bool[] BoolArray(int N, Func<string, bool> parser)
    {
        bool[] ret = new bool[N];
        for(int i = 0; i < N; i++)
        {
            ret[i] = Scanner.Bool(parser);
        }
        return ret;
    }
    public static string String
    {
        get
        {
            return enumerator.Next();
        }
    }
    public static int Int
    {
        get
        {
            return String.Int();
        }
    }
    public static long Long
    {
        get
        {
            return String.Long();
        }
    }
    public static double Double
    {
        get
        {
            return String.Double();
        }
    }
    public static char Char
    {
        get
        {
            return char.Parse(String);
        }
    }
    public static bool Bool(Func<string, bool> parser)
    {
        return parser(Scanner.String);
    }
    public static Tuple<int, int> IntTuple
    {
        get
        {
            return new Tuple<int, int>(Int, Int);
        }
    }
}
public class SegmentTree<T>
{
    private Node root;
    private Func<T, T, T> solver;

    public SegmentTree(IList<T> data, Func<T, T, T> solver)
    {
        this.solver = solver;
        this.root = new Node(data, this, 0, data.Count);
    }

    public T Get(int left, int right)
    {
        return root.Get(left, right);
    }

    public T Get(params Tuple<int, int>[] ranges)
    {
        bool first = true;
        T value = default(T);
        foreach(Tuple<int, int> range in ranges)
        {
            if(range.Item2 - range.Item1 > 0)
            {
                if (first)
                {
                    value = root.Get(range.Item1, range.Item2);
                    first = true;
                }
                else
                {
                    value = solver(value, root.Get(range.Item1, range.Item2));
                }
            }
        }
        return value;
    }

    private class Node
    {
        private Node left;
        private Node right;
        private SegmentTree<T> segmentTree;
        private T value;

        private int start;
        private int end;
        private int mid { get { return this.start + ((this.end - this.start) / 2); } }

        public Node(IList<T> data, SegmentTree<T> segmentTree, int start, int end)
        {
            this.segmentTree = segmentTree;
            this.start = start;
            this.end = end;


            int length = end - start;
            if (length == 1)
            {
                value = data[start];
            }
            else if (length == 2)
            {
                this.left = new Node(data, segmentTree, start, start + 1);
                this.right = new Node(data, segmentTree, start + 1, start + 2);
                this.value = this.segmentTree.solver(left.value, right.value);
            }
            else
            {
                int mid = start + (length / 2);
                this.left = new Node(data, segmentTree, start, mid);
                this.right = new Node(data, segmentTree, mid, end);
                this.value = this.segmentTree.solver(left.value, right.value);
            }
        }

        public T Get(int start, int end)
        {
            if (this.start == start && this.end == end) return value;

            int mid = this.mid;

            //  右のみ
            if(start >= mid)
            {
                return right.Get(start, end);
            }
            //  左のみ
            else if(end <= mid)
            {
                return left.Get(start, end);
            }
            //  両方
            else
            {
                T l = left.Get(start, mid);
                T r = right.Get(mid, end);
                return segmentTree.solver(l, r);
            }
        }
    }
}
public static class LinqExtension
{
    /*
    public static IEnumerable<Tuple<T, int>> GroupCount<T>(this IEnumerable<T> self)
    {
        return self.GroupBy(a => a).Select(g => new Tuple<T, int>(g.Key, g.Count()));
    }
    */
    public static SegmentTree<T> ToSegmentTree<T>(this IEnumerable<T> self, Func<T, T, T> solver)
    {
        return new SegmentTree<T>(self.ToArray(), solver);
    }
    public static T LeftBinarySearch<T>(this IEnumerable<T> self, Func<T, bool> solve, T min = default(T), T max = default(T))
    {
        int index = self.LeftBinarySearchIndex(solve);

        return self.Get(index, min, max);
    }
    public static T RightBinarySearch<T>(this IEnumerable<T> self, Func<T, bool> solve, T min = default(T), T max = default(T))
    {
        int index = self.RightBinarySearchIndex(solve);

        return self.Get(index, min, max);
    }
    public static int LeftBinarySearchIndex<T>(this IEnumerable<T> self, Func<T, bool> solve)
    {
        int ng = -1;
        int ok = self.Count();

        while (Math.Abs(ok - ng) > 1)
        {
            int mid = (ok + ng) / 2;

            if (solve(self.ElementAt(mid)))
            {
                ok = mid;
            }
            else
            {
                ng = mid;
            }
        }

        return ok;
    }
    public static int RightBinarySearchIndex<T>(this IEnumerable<T> self, Func<T, bool> solve)
    {
        int ng = self.Count();
        int ok = -1;

        while (Math.Abs(ok - ng) > 1)
        {
            int mid = (ok + ng) / 2;

            if (solve(self.ElementAt(mid)))
            {
                ok = mid;
            }
            else
            {
                ng = mid;
            }
        }

        return ok;
    }
    public static T Get<T>(this IEnumerable<T> self, int index, T min, T max)
    {
        if (index < 0) return min;
        if (index >= self.Count()) return max;

        return self.ElementAt(index);
    }
    public static IList<T> Fill<T>(this IList<T> self, Func<int, T> func)
    {
        for (int i = 0; i < self.Count; i++)
        {
            self[i] = func(i);
        }

        return self;
    }
    public static IList<T> Fill<T>(this IList<T> self, T value)
    {
        for (int i = 0; i < self.Count; i++)
        {
            self[i] = value;
        }

        return self;
    }
    public static T[] Fill<T>(this T[] self, T value)
    {
        for (int i = 0; i < self.Length; i++)
        {
            self[i] = value;
        }

        return self;
    }
    public static T Next<T>(this IEnumerator<T> self)
    {
        self.MoveNext();
        return self.Current;
    }
    public static void Write(this IEnumerable<bool> self)
    {
        StringBuilder sb = new StringBuilder();
        foreach (bool b in self)
        {
            sb.Append(b ? "□" : "■");
        }
        Console.WriteLine(sb.ToString());
    }
    public static U[] SelectArray<T, U>(this IEnumerable<T> self, Func<T, U> func)
    {
        U[] array = new U[self.Count()];

        int i = 0;
        foreach (T t in self)
        {
            array[i] = func(t);
            i++;
        }

        return array;
    }
    public static List<U> SelectList<T, U>(this IEnumerable<T> self, Func<T, U> func)
    {
        List<U> list = new List<U>(self.Count());

        foreach (T t in self)
        {
            list.Add(func(t));
        }

        return list;
    }
}
public static class IntExtensiton
{
    public static long C(this int self, int n)
    {
        return Factorial(self) / Factorial(n);
    }
    public static long Factorial(this int self)
    {
        int ret = self;
        for(int i = self - 1; i >= 1; i--)
        {
            ret *= i;
        }

        return ret;
    }
    public static long Factorial(this int self, int c)
    {
        int ret = self;
        for(int i = self - 1; i >= Math.Max(1, self - c - 1); i--)
        {
            ret *= i;
        }
        return ret;
    }
    public static int BitCount(this int bit, int digit = 32)
    {
        int count = 0;
        for (int i = (digit - 1); i >= 0; i--)
        {
            if (bit.GetBit(i)) count++;
        }
        return count;
    }
    public static bool GetBit(this int bit, int digit)
    {
        int mask = (1 << digit);
        return (bit & mask) == mask;
    }
    public static int SetBit(this int bit, int digit)
    {
        return (bit | (1 << digit));
    }
    public static string BitToString(this int bit, int digit = 32)
    {
        StringBuilder sb = new StringBuilder();

        for (int i = (digit - 1); i >= 0; i--)
        {
            sb.Append(bit.GetBit(i) ? "1" : "0");
        }

        return sb.ToString();
    }
    public static bool IsDivisor(this int self, int target)
    {
        return self % target == 0;
    }
    public static IEnumerable<int> Divisors(this int self)
    {
        for (int i = 1; i * i <= self; i++)
        {
            if (self % i == 0)
            {
                yield return i;
                if (i * i != self) yield return self / i;
            }
        }
    }
    public static IEnumerable<int> PrimeFactors(this int self)
    {
        int i = 2;
        int tmp = self;

        while (i * i <= self)
        {
            if (tmp % i == 0)
            {
                tmp /= i;
                yield return i;
            }
            else
            {
                i++;
            }
        }
        if (tmp != 1) yield return tmp;
    }
    public static bool NeighboringBit(this int self, int digit = 32)
    {
        if (digit < 2) return false;
        return Enumerable.Range(0, digit - 1).Where(j => self.GetBit(j) && self.GetBit(j + 1)).Any();
    }
}
public static class LongExtensition
{
    public static long BitCount(this long bit, int digit = 64)
    {
        long count = 0;
        for (int i = (digit - 1); i >= 0; i--)
        {
            if (bit.GetBit(i)) count++;
        }
        return count;
    }

    public static bool GetBit(this long bit, int digit)
    {
        long mask = (1L << digit);
        return (bit & mask) == mask;
    }

    public static long SetBit(this long bit, int digit)
    {
        return bit | (1L << digit);
    }

    public static string BitToString(this long bit, int digit = 64)
    {
        StringBuilder sb = new StringBuilder();

        for (int i = (digit - 1); i >= 0; i--)
        {
            sb.Append(bit.GetBit(i) ? "1" : "0");
        }

        return sb.ToString();
    }

    public static bool IsDivisor(this long self, int target)
    {
        return self % target == 0;
    }
}
public static class StringExtensiton
{
    public static void Print(this string str) => Console.WriteLine(str);
    public static int Int(this string str) => int.Parse(str);
    public static long Long(this string str) => long.Parse(str);
    public static double Double(this string str) => double.Parse(str);
}
public class F
{
    public static bool ChMax<T>(ref T x, T y) where T : IComparable
    {
        if (x.CompareTo(y) < 0)
        {
            x = y;
            return true;
        }
        return false;
    }

    public static bool ChMin<T>(ref T x, T y) where T : IComparable
    {
        if (x.CompareTo(y) > 0)
        {
            x = y;
            return true;
        }
        return false;
    }

    public static void Swap<T>(ref T x, ref T y)
    {
        T tmp = x;

        x = y;
        y = tmp;
    }

    public static int Gcd(int a, int b)
    {
        if (a < b) return Gcd(b, a);
        while (b != 0)
        {
            var remainder = a % b;
            a = b;
            b = remainder;
        }
        return a;
    }

    public static long Gcd(long a, long b)
    {
        if (a < b) return Gcd(b, a);
        while (b != 0)
        {
            var remainder = a % b;
            a = b;
            b = remainder;
        }
        return a;
    }
}
