using System;
using System.Collections.Generic;
using System.Linq;

public class Prog
{
    public void run()
    {
        var S = Console.ReadLine();
        var flag = true;
        while(true)
        {
            if(S.Length >= 8)
            {
                var X = S.Substring(0, 8);
                if(X == "dreamdre" || X == "dreamera")
                {
                    S = S.Substring(5, S.Length - 5);
                }else if(X == "dreamerd" || X == "dreamere")
                {
                    S = S.Substring(7, S.Length - 7);
                }else if(X == "erasedre" || X == "eraseera")
                {
                    S = S.Substring(5, S.Length - 5);
                }else if(X == "eraserer" || X == "eraserdr")
                {
                    S = S.Substring(6, S.Length - 6);
                }else
                {
                    flag = false;
                    break;
                }
            }else
            {
                if(S == "dream")
                {
                    break;
                }else if(S == "dreamer")
                {
                    break;
                }else if(S == "erase")
                {
                    break;
                }else if(S == "eraser")
                {
                    break;
                }else
                {
                    flag = false;
                    break;
                }
            }
        }
        if(flag == true)
        {
            Console.WriteLine("YES");
        }else
        {
            Console.WriteLine("NO");
        }
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
