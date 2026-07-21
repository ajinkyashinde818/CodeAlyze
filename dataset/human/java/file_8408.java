using System;
using System.Text;
using System.Collections.Generic;
using System.Linq;

public class HelloWorld
{
    static public void Main ()
    {
        var AB = Console.ReadLine().Split().Select(a => long.Parse(a)).ToArray();
        var A = AB[0];
        var B = AB[1];

        Console.WriteLine(A*B/(Gcd(A,B)));
     }
     
     public static long Gcd(long a, long b) { if (a < b) // 引数を入替えて自分を呼び出す
      return Gcd(b, a); while (b != 0) { var remainder = a % b; a = b; b = remainder; } return a; }
            
}
