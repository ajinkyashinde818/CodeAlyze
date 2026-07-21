using System;
using System.Collections.Generic;
using System.Linq;

public class Prog
{
    public void run()
    {
        int N = int.Parse(Console.ReadLine());
        var input = Console.ReadLine().Split();
        int[] A = Array.ConvertAll(input, int.Parse);
        input = Console.ReadLine().Split();
        int[] B = Array.ConvertAll(input, int.Parse);
        input = Console.ReadLine().Split();
        int[] C = Array.ConvertAll(input, int.Parse);
        int Old = -5;
        int New = 0;
        int ans = 0;
        for(int i = 0; i < N; i++)
        {
            New = B[A[i] - 1];
            if(Old == A[i] - 1)
            {
                New += C[Old-1];
            }
            Old = A[i];
            ans += New;
        }
        Console.WriteLine(ans);
    }
    public static void Main()
    {
        var prog = new Prog();
        prog.run();
    }
    /*
    最小公倍数
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
    */
    //a<=c, b<=d;
}

//Array.ConvertAll(int.Parse)
//str.IndexOf("Stage",System.StringComparison.CurrentCulture)
