using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

public class Program
{
    static void Main()
    {
        string[] lineRecord = Console.ReadLine().Trim().Split(' ');
        var A = long.Parse(lineRecord[0]);
        var B = long.Parse(lineRecord[1]);

        var answer = CalcSaishouKoubaisuu(A, B);
        Console.WriteLine(answer.ToString());
    }

    /// <summary>
    /// 
    /// </summary>
    /// <returns></returns>
    private static long CalcSaishouKoubaisuu(long a, long b)
    {
        return a * b / Gcd(a, b);
    }

    // ユークリッドの互除法 
    private static long Gcd(long a, long b)
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
