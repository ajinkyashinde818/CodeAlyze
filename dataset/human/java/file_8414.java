using System;
using System.Collections.Generic;
using System.Linq;

public class Program
{
    public static void Main(string[] args)
    {
        var vals = Console.ReadLine().Split(' ').Select(x => long.Parse(x)).ToArray();
        Console.WriteLine(Lcm(vals[0], vals[1]));
    }

    public static long Lcm(long a, long b)
    {
        return a * b / Gcd(a, b);
    }

    public static long Gcd(long a, long b)
    {
        if (a < b)
        {
            return Gcd(b, a);
        }
        while (b != 0)
        {
            var remainder = a % b;
            a = b;
            b = remainder;
        }
        return a;
    }
}
