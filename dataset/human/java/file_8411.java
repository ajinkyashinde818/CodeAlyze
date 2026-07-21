using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _20191224_ATC
{
    class Program
    {
        static void Main(string[] args)
        {
            var n = Myself.NextLong();
            var a = n[0];
            var b = n[1];

            //最小公倍数を求める問題
            var lcm = Utility.Lcm(a, b);
            Console.WriteLine(lcm);
        }

        /// <summary>
        /// コンソール出力関数
        /// </summary>
        /// <typeparam name="T"></typeparam>
        /// <param name="a"></param>
        private static void Print<T>(T a)
        {
            Console.WriteLine(a);
        }

        private static void ABC148_B()
        {
            var m = int.Parse(Console.ReadLine());
            var str = Console.ReadLine().ToString().Split(' ');
            var s = str[0];
            var t = str[1];

            //Zip : 2つのリストから一個ずつ取り出して結合する
            //SelectMany : 結合したものを1文字ずつ1つのリストにまとめる
            var output = s.Zip(t, (x, y) => new[] { x, y }).SelectMany(xs => xs);
            //foreach (var item in output)
            //{
            //    Console.WriteLine(item);
            //}

            //char型のリストから文字列を生成
            Console.WriteLine(string.Join("", output));
        }

        private static void ABC148_A()
        {
            var a = int.Parse(Console.ReadLine());
            var b = int.Parse(Console.ReadLine());
            var c = Enumerable.Range(1, 3).Where(x => x != a && x != b).First();
            Console.WriteLine(c);
        }
    }

    public class Myself
    {
        public static List<int> NextInt()
        {
            return Console.ReadLine().Split(' ').Select(int.Parse).ToList();
        }

        public static List<long> NextLong()
        {
            return Console.ReadLine().Split(' ').Select(long.Parse).ToList();
        }

        public static List<double> NextDouble()
        {
            return Console.ReadLine().Split(' ').Select(double.Parse).ToList();
        }

        public static List<string> NextString()
        {
            return Console.ReadLine().Split(' ').ToList();
        }

        public static void Swap<T>(ref T a, ref T b)
        {
            T temp = a;
            a = b;
            b = temp;
        }
    }

    public struct Point
    {
        public double X
        {
            get;
            set;
        }
        public double Y
        {
            get;
            set;
        }

        public Point(double x, double y)
        {
            X = x;
            Y = y;
        }

        public static Point CalcOffsetPoint(Point a, Point b)
        {
            b.X -= a.X;
            b.Y -= a.Y;

            return new Point(b.X, b.Y);
        }

        public static double CalcArea(Point a, Point b)
        {
            return Math.Abs((a.X * b.Y) - (a.Y * b.X)) / 2;
        }
    }

    class Utility
    {
        // 最小公倍数
        public static long Lcm(long a, long b)
        {
            return a * b / Gcd(a, b);
        }

        // ユークリッドの互除法 最大公約数
        private static long Gcd(long a, long b)
        {
            if (a < b)
            {
                return Gcd(b, a);
            }
            long d = 0;
            do
            {
                d = a % b;
                a = b;
                b = d;
            } while (d != 0);
            return a;
        }

        //private static int Gcd(int a, int b)
        //{
        //    if (a > b)
        //        // 引数を入替えて自分を呼び出す
        //        return Gcd(b, a);
        //    while (b != 0)
        //    {
        //        var remainder = a % b;
        //        a = b;
        //        b = remainder;
        //    }
        //    return a;
        //}
    }
}
