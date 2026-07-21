using System.Collections;
using System.Text;
using System.Threading.Tasks;
using static System.Math;
using static System.Console;
using System.Collections.Generic;
using System.Linq;
using System;
using System.Numerics;
using System.IO.Pipes;
using System.Threading;
using System.Net;

class Program
{
    #region Reader
   
    static string ReadStr => Console.ReadLine();
    static string[] ReadStrs => Console.ReadLine().Split(' ');
    static int ReadInt => Convert.ToInt32(Console.ReadLine());
    static int[] ReadInts => Console.ReadLine().Split(' ').Select(s => Convert.ToInt32(s)).ToArray();
    static long ReadLong => Convert.ToInt64(Console.ReadLine());
    static long[] ReadLongs => Console.ReadLine().Split(' ').Select(s => Convert.ToInt64(s)).ToArray();
    static long[,] ReLongMatrix(int r, int c)
    {
        var mat = new long[r, c];
        for (int i = 0; i < r; ++i)
        {
            var x = ReadLongs;
            for (int j = 0; j < c; ++j)
            {
                mat[i, j] = x[j];
            }
        }
        return mat;
    }
    static Tuple<string, string>[] ReTupleStr(int n)
    {
        List<Tuple<string, string>> list = new List<Tuple<string, string>>();
        for (int i = 0; i < n; ++i)
        {
            var ab = ReadStrs;
            list.Add(new Tuple<string, string>(ab[0], ab[1]));
        }
        return list.ToArray();
    }
    static Tuple<long, long>[] ReTupleLong(int n)
    {
        List<Tuple<long, long>> list = new List<Tuple<long, long>>();
        for (int i = 0; i < n; ++i)
        {
            var ab = ReadLongs;
            list.Add(new Tuple<long, long>(ab[0], ab[1]));
        }
        return list.ToArray();
    }
    static Tuple<int, int>[] ReadTupleInt(int n)
    {
        List<Tuple<int, int>> list = new List<Tuple<int, int>>();
        for (int i = 0; i < n; ++i)
        {
            var ab = ReadInts;
            list.Add(new Tuple<int, int>(ab[0], ab[1]));
        }
        return list.ToArray();
    }
    static Tuple<double, double>[] ReTupleDouble(int n)
    {
        List<Tuple<double, double>> list = new List<Tuple<double, double>>();
        for (int i = 0; i < n; ++i)
        {
            var ab = ReadLongs;
            list.Add(new Tuple<double, double>(ab[0], ab[1]));
        }
        return list.ToArray();
    }
    static Dictionary<int, HashSet<int>> ReAdjacencyList(int N, int M)
    {
        Dictionary<int, HashSet<int>> dict = new Dictionary<int, HashSet<int>>();
        for (int i = 0; i <= N; ++i)
        {
            dict.Add(i, new HashSet<int>());
        }
        for (int i = 0; i < M; ++i)
        {
            var ab = ReadInts;
            dict[ab[0]].Add(ab[1]);
            dict[ab[1]].Add(ab[0]);
        }
        return dict;
    }
    #endregion
    static void Swap<T>(ref T a, ref T b)
    {
        T temp = a;
        a = b;
        b = temp;
    }
    static int mod = (int)Pow(10, 9) + 7;


    public static long GetInv(long a, long mod = 1000000007)
    {
        return PowerMod(a, mod - 2, mod);
    }
    public static long Combination(long a, long b, long mod = 1000000007)
    {
        if (b < 0 || b > a) return 0;
        if (b > a / 2) b = a - b;
        long numerator = Factorial(a, mod);
        long denominator = (Factorial(b, mod) * Factorial(a - b, mod)) % mod;

        return (numerator * GetInv(denominator, mod)) % mod;
    }
    public static long Factorial(long n, long mod = 1000000007)
    {
        if (n == 0) return 1;
        if (n == 1) return 1;
        long ans = n;
        for (int i = 2; i < n; i++)
        {
            ans = (ans * i) % mod;
        }

        return ans;
    }
    private static long PowerMod(long a, long n, long mod = 1000000007)
    {
        if (n == 0) return 1;
        if (n == 1) return a;

        long p = PowerMod(a, n / 2, mod);
        if (n % 2 == 1) return ((p * p) % mod * a) % mod;
        else return (p * p) % mod;
    }

    /// <summary>
    /// 最小公倍数
    /// </summary>
    /// <param name="a"></param>
    /// <param name="b"></param>
    /// <returns></returns>
    public static long Lcm(long a, long b)
    {
        return a * b / Gcd(a, b);
    }


    /// <summary>
    /// 最大公約数
    /// </summary>
    /// <param name="a"></param>
    /// <param name="b"></param>
    /// <returns></returns>
    public static long Gcd(long a, long b)
    {
        if (a < b)
            // 引数を入替えて自分を呼び出す
            return Gcd(b, a);
        while (b != 0)
        {
            var remainder = a % b;
            a = b;
            b = remainder;
        }
        return a;
    }

    public struct MyStruct
    {
        public MyStruct(long a,long b)
        {
            A = a;
            B = b;
        }
        public long A;
        public long B;

    }


    public class PriorityQueue<T> : IEnumerable<T>
    {
        private readonly List<T> _data = new List<T>();
        private readonly IComparer<T> _comparer;
        private readonly bool _isDescending;

        public PriorityQueue(IComparer<T> comparer, bool isDescending = true)
        {
            _comparer = comparer;
            _isDescending = isDescending;
        }

        public PriorityQueue(Comparison<T> comparison, bool isDescending = true)
            : this(Comparer<T>.Create(comparison), isDescending)
        {
        }

        public PriorityQueue(bool isDescending = true)
            : this(Comparer<T>.Default, isDescending)
        {
        }

        public void Enqueue(T item)
        {
            _data.Add(item);
            var childIndex = _data.Count - 1;
            while (childIndex > 0)
            {
                var parentIndex = (childIndex - 1) / 2;
                if (Compare(_data[childIndex], _data[parentIndex]) >= 0)
                    break;
                Swap(childIndex, parentIndex);
                childIndex = parentIndex;
            }
        }

        public T Dequeue()
        {
            var lastIndex = _data.Count - 1;
            var firstItem = _data[0];
            _data[0] = _data[lastIndex];
            _data.RemoveAt(lastIndex--);
            var parentIndex = 0;
            while (true)
            {
                var childIndex = parentIndex * 2 + 1;
                if (childIndex > lastIndex)
                    break;
                var rightChild = childIndex + 1;
                if (rightChild <= lastIndex && Compare(_data[rightChild], _data[childIndex]) < 0)
                    childIndex = rightChild;
                if (Compare(_data[parentIndex], _data[childIndex]) <= 0)
                    break;
                Swap(parentIndex, childIndex);
                parentIndex = childIndex;
            }
            return firstItem;
        }

        public T Peek()
        {
            return _data[0];
        }

        private void Swap(int a, int b)
        {
            var tmp = _data[a];
            _data[a] = _data[b];
            _data[b] = tmp;
        }

        private int Compare(T a, T b)
        {
            return _isDescending ? _comparer.Compare(b, a) : _comparer.Compare(a, b);
        }

        public int Count => _data.Count;

        public IEnumerator<T> GetEnumerator()
        {
            return _data.GetEnumerator();
        }

        IEnumerator IEnumerable.GetEnumerator() => GetEnumerator();
    }
    public class PriorityQueue<TKey, TValue> : IEnumerable<TValue>
    {
        private readonly List<KeyValuePair<TKey, TValue>> _data = new List<KeyValuePair<TKey, TValue>>();
        private readonly bool _isDescending;
        private readonly Func<TValue, TKey> _keySelector;
        private readonly IComparer<TKey> _keyComparer;

        public PriorityQueue(Func<TValue, TKey> keySelector, bool isDescending = true)
            : this(keySelector, Comparer<TKey>.Default, isDescending)
        {
        }

        public PriorityQueue(Func<TValue, TKey> keySelector, IComparer<TKey> keyComparer, bool isDescending = true)
        {
            _keySelector = keySelector;
            _keyComparer = keyComparer;
            _isDescending = isDescending;
        }

        public void Enqueue(TValue item)
        {
            _data.Add(new KeyValuePair<TKey, TValue>(_keySelector(item), item));
            var childIndex = _data.Count - 1;
            while (childIndex > 0)
            {
                var parentIndex = (childIndex - 1) / 2;
                if (Compare(_data[childIndex].Key, _data[parentIndex].Key) >= 0)
                    break;
                Swap(childIndex, parentIndex);
                childIndex = parentIndex;
            }
        }

        public TValue Dequeue()
        {
            var lastIndex = _data.Count - 1;
            var firstItem = _data[0];
            _data[0] = _data[lastIndex];
            _data.RemoveAt(lastIndex--);
            var parentIndex = 0;
            while (true)
            {
                var childIndex = parentIndex * 2 + 1;
                if (childIndex > lastIndex)
                    break;
                var rightChild = childIndex + 1;
                if (rightChild <= lastIndex && Compare(_data[rightChild].Key, _data[childIndex].Key) < 0)
                    childIndex = rightChild;
                if (Compare(_data[parentIndex].Key, _data[childIndex].Key) <= 0)
                    break;
                Swap(parentIndex, childIndex);
                parentIndex = childIndex;
            }
            return firstItem.Value;
        }

        public TValue Peek()
        {
            return _data[0].Value;
        }

        private void Swap(int a, int b)
        {
            var tmp = _data[a];
            _data[a] = _data[b];
            _data[b] = tmp;
        }

        private int Compare(TKey a, TKey b)
        {
            return _isDescending ? _keyComparer.Compare(b, a) : _keyComparer.Compare(a, b);
        }

        public int Count => _data.Count;

        public IEnumerator<TValue> GetEnumerator()
        {
            return _data.Select(r => r.Value).GetEnumerator();
        }

        IEnumerator IEnumerable.GetEnumerator() => GetEnumerator();
    }



    public static IEnumerable<long> PrimeFactors(long n)
    {
        long i = 2;
        long tmp = n;

        while (i * i <= n) //※1
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
        if (tmp != 1) yield return tmp;//最後の素数も返す
    }




    static void Main()
    {
        long n = ReadLong;

        var Ds = PrimeFactors(n).ToList();

        Dictionary<long, int> d = new Dictionary<long, int>();

        for (int i = 0; i < Ds.Count; i++)
        {
            if(d.ContainsKey(Ds[i]))d[Ds[i]]++;
            else d.Add(Ds[i], 1);
        }

        int count = 0;

        foreach (var item in d)
        {
            int v = item.Value;
            int c = 0;
            int i = 1;
            while (v>=i)
            {
                v-=i;
                c++;
                i++;
            }
            count += c;
        }

        WriteLine(count);

    }








}
