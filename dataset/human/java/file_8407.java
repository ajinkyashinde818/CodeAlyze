using System;
using System.Linq;
using System.Collections.Generic;

namespace ConsoleApp2
{
    public class Program
    {

        static long D = (long)Math.Pow(10, 9) + 7;

        public static void Main(string[] args)
        {
            int mod = 2019;

            int[] AB = Read(Console.ReadLine());
            int A = AB[0];
            int B = AB[1];

            
            Console.WriteLine(Lcm(A,B));
            Console.ReadLine();
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


        private static int[] Read(string input)
        {
            string[] strings = input.Split(' ');
            int num = strings.Length;
            int[] ints = new int[num];
            for (int i = 0; i < num; i++)
            {
                ints[i] = int.Parse(strings[i]);
            }
            
            return ints;
        }


    }


}
