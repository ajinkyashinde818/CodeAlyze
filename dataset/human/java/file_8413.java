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
        public static void Main(string[] args)
        {
            new Program().Solve(new ConsoleInput(Console.In, ' '));
            Console.ReadLine();
        }

        public void Solve(ConsoleInput cin)
        {
            int[] data = cin.ReadIntArray(2);

            Console.WriteLine(Lcm(data[0], data[1]));
        }

        // 以下は消さないこと

        //a^n mod MODを求める(繰り返し2情報を用いた高速版)
        static long modpow(long a, long n, long MOD)
        {
            if (n == 0)
                return 1;
            if (n % 2 == 0)
            {
                long temp = modpow(a, n / 2, MOD);
                return temp * temp % MOD;
            }

            return a * modpow(a, n - 1, MOD) % MOD;
        }

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
    }

    public class Vector2
    {
        public int x;
        public int y;

        public Vector2(int _x, int _y)
        {
            x = _x;
            y = _y;
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
        public ulong ReadULong { get { return ulong.Parse(Read); } }
        public double ReadDouble { get { return double.Parse(Read); } }
        public string[] ReadStrArray(long N) { var ret = new string[N]; for (long i = 0; i < N; ++i) ret[i] = Read; return ret; }
        public int[] ReadIntArray(long N) { var ret = new int[N]; for (long i = 0; i < N; ++i) ret[i] = ReadInt; return ret; }
        public long[] ReadLongArray(long N) { var ret = new long[N]; for (long i = 0; i < N; ++i) ret[i] = ReadLong; return ret; }
        public ulong[] ReadULongArray(long N) { var ret = new ulong[N]; for (long i = 0; i < N; ++i) ret[i] = ReadULong; return ret; }
    }

    public class Util
    {
        //nCrを計算したいときに使用
        public static ModInt Comb(int n, int r)
        {
            ModInt res = 1;
            for (int i = 1; i <= r; i++)
            {
                res *= n;
                res /= i;
                n--;
            }
            return res;
        }

        //n^mを計算
        public static ModInt Power(ModInt n, long m)
        {
            ModInt pow = n;
            ModInt res = 1;
            while (m > 0)
            {
                if ((m & 1) == 1) res *= pow;
                pow *= pow;
                m >>= 1;
            }
            return res;
        }
    }


    public struct ModInt
    {
        public const int Mod = 1000000007;
        const long POSITIVIZER = ((long)Mod) << 31;
        long Data;
        public ModInt(long data) { if ((Data = data % Mod) < 0) Data += Mod; }
        public static implicit operator long(ModInt modInt) => modInt.Data;
        public static implicit operator ModInt(long val) => new ModInt(val);
        public static ModInt operator -(ModInt a, int b) => new ModInt() { Data = (a.Data - b + POSITIVIZER) % Mod };
        public static ModInt operator -(ModInt a, ModInt b) { long res = a.Data - b.Data; return new ModInt() { Data = res < 0 ? res + Mod : res }; }
        public static ModInt operator *(ModInt a, int b) => new ModInt(a.Data * b);
        public static ModInt operator *(ModInt a, ModInt b) => new ModInt() { Data = a.Data * b.Data % Mod };
        public static ModInt operator /(ModInt a, ModInt b) => new ModInt() { Data = a.Data * GetInverse(b) % Mod };
        public override int GetHashCode() => (int)Data;
        static long GetInverse(long a)
        {
            long div, p = Mod, x1 = 1, y1 = 0, x2 = 0, y2 = 1;
            while (true)
            {
                if (p == 1) return x2 + Mod; div = a / p; x1 -= x2 * div; y1 -= y2 * div; a %= p;
                if (a == 1) return x1 + Mod; div = p / a; x2 -= x1 * div; y2 -= y1 * div; p %= a;
            }
        }
    }
}
