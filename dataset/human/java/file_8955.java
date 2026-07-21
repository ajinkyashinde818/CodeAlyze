using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using static System.Console;
using static System.Math;

namespace atcoder
{
    class Program
    {
        public T Min<T>(params T[] a)
        {
            if (a.Length == 0) return default(T);

            T min = a[0];
            for (int i = 1; i < a.Length; i++)
            {
                if ((dynamic)min > (dynamic)a[i]) min = a[i];
            }
            return min;
        }

        public T Max<T>(params T[] a)
        {
            if (a.Length == 0) return default(T);

            T max = a[0];
            for (int i = 1; i < a.Length; i++)
            {
                if ((dynamic)max < (dynamic)a[i]) max = a[i];
            }
            return max;
        }

        public T Lcm<T>(T a, T b)
        {
            return (dynamic)a * (dynamic)b / Gcd((dynamic)a, (dynamic)b);
        }

        public T Gcd<T>(T a, T b)
        {
            if ((dynamic)a < (dynamic)b)
                return Gcd(b, a);
            while ((dynamic)b != 0)
            {
                var remainder = (dynamic)a % (dynamic)b;
                a = b;
                b = remainder;
            }
            return a;
        }

        static void Main(string[] args)
        {
            if (args.Length > 0 && args[0] == "Debug")
            {
                while (true)
                    new Program().Solve(new ConsoleInput(In));
            }
            else new Program().Solve(new ConsoleInput(In));
        }

        public void Solve(ConsoleInput input)
        {
            var a = input.ReadInt;
            var b = input.ReadInt;
            var k = input.ReadInt;

            var ans = new List<int>();
            for (var i = 1; i <= a; i++)
            {
                if (a % i == 0 && b % i == 0) ans.Add(i);
            }
            ans.Sort();
            ans.Reverse();
            WriteLine($"{ans[k-1]}");
        }
    }

    public class ConsoleInput
    {
        private readonly System.IO.TextReader _stream;
        private readonly char _separator;
        private Queue<string> inputStream;
        public ConsoleInput(System.IO.TextReader stream, char separator = ' ')
        {
            _separator = separator;
            _stream = stream;
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
}
