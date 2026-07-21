using System;
using System.Text;
using System.Linq;
using System.Collections;
using System.Collections.Generic;
using static System.Console;
using static System.Math;
using static AtCoder.AtCoderLib;

namespace AtCoder
{
    class Program
    {
        static void Main(string[] args)
        {
            new ABC125().SolveD(new ConsoleInput(Console.In, ' '));
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

    public static class AtCoderLib
    {
        // ユークリッドの互除法 
        public static int Gcd(int a, int b)
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
    }
  class ABC125
  {
    public void SolveD(ConsoleInput cin)
        {
            var n = cin.ReadInt;
            var A = cin.ReadIntArray(n);
            int count = 0;
            long sum = 0;
            int min = (int)Pow(10, 9);
            foreach (var a in A)
            {
                sum += Abs(a);
                if (min > Abs(a)) min = Abs(a);
                if (a <= 0) count++;
            }
            if (count % 2 == 1) sum -= min * 2;
            WriteLine(sum);
            ReadLine();
        }
  }
}
