using System;
using System.Text;
using System.Linq;
using System.Collections;
using System.Collections.Generic;
using static System.Console;
using static System.Math;
using System.Numerics;

namespace AtCoder
{
    public class Program
    {
        // 最小公倍数
        public static long Lcm(long a, long b)
        {
            return a * b / Gcd(a, b);
        }

        // ユークリッドの互除法 
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

        public static void Main(string[] args)
        {
            new Program().Solve(new ConsoleInput(Console.In, ' '));
            Console.ReadLine();
        }

        public void Solve(ConsoleInput cin)
        {
            int[] data = cin.ReadIntArray(2);
            if (data[0] >= 10)
            {
                Console.WriteLine(data[1]);
            }
            else
            {
                Console.WriteLine(data[1] + 100 * (10 - data[0]));
            }
        }

    }
    public class ConsoleInput
    {
        private readonly System.IO.TextReader _stream;
        private char _separator = ' ';
        private Queue<string> inputStream;
        public ConsoleInput(System.IO.TextReader stream, char separator = ' ')
        {
            this._separator = separator;
            this._stream = stream;
            inputStream = new Queue<string>();
        }
        public string Read
        {
            get
            {
                if (inputStream.Count != 0) return inputStream.Dequeue();
                string[] tmp = _stream.ReadLine().Split(_separator);
                for (int i = 0; i < tmp.Length; ++i)
                    inputStream.Enqueue(tmp[i]);
                return inputStream.Dequeue();
            }
        }
        public string ReadLine { get { return _stream.ReadLine(); } }
        public int ReadInt { get { return int.Parse(Read); } }
        public long ReadLong { get { return long.Parse(Read); } }
        public double ReadDouble { get { return double.Parse(Read); } }
        public string[] ReadStrArray(long N) { var ret = new string[N]; for (long i = 0; i < N; ++i) ret[i] = Read; return ret; }
        public int[] ReadIntArray(long N) { var ret = new int[N]; for (long i = 0; i < N; ++i) ret[i] = ReadInt; return ret; }
        public long[] ReadLongArray(long N) { var ret = new long[N]; for (long i = 0; i < N; ++i) ret[i] = ReadLong; return ret; }
    }

    class Mod
    {
        public int N { get; }
        private readonly List<long> fac = new List<long>() { 1, 1 };
        private readonly List<long> inv = new List<long>() { 0, 1 };
        private readonly List<long> facInv = new List<long>() { 1, 1 };

        /// <summary>
        /// コンストラクタでmod N のNの値を決める
        /// </summary>
        /// <param name="n"></param>
        public Mod(int n) { N = n; }

        /// <summary>
        /// 四則演算は下で
        /// </summary>
        /// <param name="a"></param>
        /// <param name="b"></param>
        /// <returns></returns>
        public long Add(long a, long b) => (a % N + b % N + N) % N;
        public long Sub(long a, long b) => Add(a, -b);
        public long Mul(long a, long b) => (a % N * b % N + N) % N;
        public long Div(long a, long b) => Mul(a, Inv(b));

        public long Sum(params long[] args) => args.Aggregate(Add);

        public long Inv(long a)
        {
            if (a < inv.Count) return inv[(int)a];
            long b = N, x = 1, y = 0, tmp;
            while (b != 0)
            {
                var q = a / b;
                tmp = y;
                y = x - q * y;
                x = tmp;
                tmp = b;
                b = a - q * b;
                a = tmp;
            }
            return (x % N + N) % N;
        }

        public long Pow(long a, long n)
        {
            var result = 1L;
            while (n > 0)
            {
                if ((n & 1) == 1) result = Mul(result, a);
                a = Mul(a, a);
                n >>= 1;
            }
            return result;
        }

        public void InitSeq(int n)
        {
            for (var i = fac.Count; i <= n; i++)
            {
                fac.Add(fac[i - 1] * i % N);
                inv.Add(N - inv[N % i] * (N / i) % N);
                facInv.Add(facInv[i - 1] * inv[i] % N);
            }
        }

        public long Fac(int n)
        {
            InitSeq(n);
            return fac[n];
        }

        public long Per(int n, int k)
        {
            if (n < k || n < 0 || k < 0) return 0;
            InitSeq(n);
            return fac[n] * facInv[n - k] % N;
        }

        public long Com(int n, int k)
        {
            if (n < k || n < 0 || k < 0) return 0;
            InitSeq(n);
            return fac[n] * (facInv[k] * facInv[n - k] % N) % N;
        }
    }
}
