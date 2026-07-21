using System;
using System.Linq;
using System.Collections.Generic;
public class Test
{
    public static void Main()
    {
        var input = Console.ReadLine().Split(' ').Select(v => int.Parse(v)).ToArray();
        Console.WriteLine(Div(Gcd(input[0], input[1]),input[2]));
        Console.ReadKey();
    }
    public static int Gcd(int a, int b)
    {
        if (a < b)
            return Gcd(b, a);
        while (b != 0)
        {
            var remainder = a % b;
            a = b;
            b = remainder;
        }
        return a;
    }
    public static int Div(int a, int b)
    {
        for (int i = 105;true;i--)
        {
            if (a % i == 0)
            {
                b--;
            }
            if(b==0)
                return i;
        }
    }
}
