using System;
using System.Collections.Generic;
using System.Linq;

namespace AtCoder
{
    class Program
    {
        static void Main(string[] args)
        {
            //[summary]C - Snack
            var line = ReadLine();
            int A = line[0];
            int B = line[1];

            var lib = new Library.Gcd();
            Console.WriteLine(lib.GetLcm(A, B));            
        }

        static List<int> ReadLine()
        {
            var line = Console.ReadLine();
            var arr = line.Split(' ');

            return arr.Select(x => int.Parse(x)).ToList();
        }
    }
}

namespace Library
{
    public class Gcd
    {
        public long GetGcd(long a, long b)
        {
            //[summary]a,b2つの数の最大公約数を求める
            //Gcd: Greatest Common Divisor
            //以下リンクを参考に実装
            //https://qiita.com/gushwell/items/e9614b4ac2bea3fc6486

            if (a < b)
            {
                //引数を入れ替えて自分を呼び出す
                return GetGcd(b, a);
            }
            else
            {
                while (b > 0)
                {
                    long remainder = a % b;

                    a = b;
                    b = remainder;
                }

                return a;
            }
        }

        public long GetLcm(long a, long b)
        {
            //[summary]a,b2つの数の最小公倍数を求める
            //Lcm: Least Common Multiple
            //以下リンクを参考に実装
            //https://qiita.com/gushwell/items/f08d0e71fa0480dbb396

            long gcd = GetGcd(a, b);

            //先に割り算をしておくとオーバーフローしない
            return a / gcd * b;
        }
    }
}
