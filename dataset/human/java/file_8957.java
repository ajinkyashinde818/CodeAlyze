using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Diagnostics;

public class Program
{
    public static void Main(string[] args)
    {
        int[] line = Scanner.IntList.ToArray();
        int A = line[0];
        int B = line[1];
        int K = line[2];

        List<int> P = new List<int>();
        foreach(int i in Enumerable.Range(1, A))
        {
            if((A % i) == 0)
            {
                P.Add(i);
            }
        }

        List<int> Q = new List<int>();
        foreach (int i in Enumerable.Range(1, B))
        {
            if ((B % i) == 0)
            {
                Q.Add(i);
            }
        }

        var R = P.Where(i => Q.Contains(i));
        int ans = R.OrderByDescending(i => i).Skip(K - 1).First();

        Console.WriteLine(ans);
        Console.ReadLine();
    }

    public static int Gcd(int a, int b)
    {
        if (a < b) return Gcd(b, a);
        while (b != 0)
        {
            var remainder = a % b;
            a = b;
            b = remainder;
        }
        return a;
    }
}

/// <summary>
/// スキャナ
/// </summary>
public class Scanner
{
    public static long Long
    {
        get
        {
            return Console.ReadLine().Long();
        }
    }

    public static int Int
    {
        get
        {
            return Console.ReadLine().Int();
        }
    }

    public static string String
    {
        get
        {
            return Console.ReadLine();
        }
    }

    public static string[] StringList
    {
        get
        {
            return Console.ReadLine().Split();
        }
    }

    public static IEnumerable<int> IntList
    {
        get
        {
            return StringList.Select(v => v.Int());
        }
    }

    public static IEnumerable<long> LongList
    {
        get
        {
            return StringList.Select(v => v.Long());
        }
    }

    public static IEnumerable<double> DoubleList
    {
        get
        {
            return StringList.Select(v => v.Double());
        }
    }
}

/// <summary>
/// Linq拡張
/// </summary>
public static class LinqExtension
{
    /// <summary>
    /// 二分探索
    /// </summary>
    /// <typeparam name="T"></typeparam>
    /// <param name="self"></param>
    /// <param name="solve"></param>
    /// <param name="min"></param>
    /// <param name="max"></param>
    /// <returns></returns>
    public static T LeftBinarySearch<T>(this IEnumerable<T> self, Func<T, bool> solve, T min, T max)
    {
        int index = self.LeftBinarySearchIndex(solve);

        return self.Get(index, min, max);
    }

    /// <summary>
    /// 二分探索
    /// </summary>
    /// <typeparam name="T"></typeparam>
    /// <param name="self"></param>
    /// <param name="solve"></param>
    /// <param name="min"></param>
    /// <param name="max"></param>
    /// <returns></returns>
    public static T RightBinarySearch<T>(this IEnumerable<T> self, Func<T, bool> solve, T min, T max)
    {
        int index = self.RightBinarySearchIndex(solve);

        return self.Get(index, min, max);
    }

    /// <summary>
    /// OutOfRange対応
    /// </summary>
    /// <typeparam name="T">型T</typeparam>
    /// <param name="self">IEnumerable</param>
    /// <param name="index">対象のインデックス</param>
    /// <param name="min">0未満のインデックスの時</param>
    /// <param name="max">配列のサイズ以上の時</param>
    /// <returns>型Tの値</returns>
    public static T Get<T>(this IEnumerable<T> self, int index, T min, T max)
    {
        if (index < 0) return min;
        if (index >= self.Count()) return max;

        return self.ElementAt(index);
    }

    /// <summary>
    /// <para>二分探索</para>
    /// <para>渡されたラムダ式の条件を満たすものの中で、一番左側のもの(インデックスが小さい)</para>
    /// </summary>
    /// <typeparam name="T">IEnumerable</typeparam>
    /// <param name="solve"></param>
    /// <returns>一番左側のインデックス</returns>
    public static int LeftBinarySearchIndex<T>(this IEnumerable<T> self, Func<T, bool> solve)
    {
        int ng = -1;
        int ok = self.Count();

        while(Math.Abs(ok - ng) > 1)
        {
            int mid = (ok + ng) / 2;

            if (solve(self.ElementAt(mid)))
            {
                ok = mid;
            }
            else
            {
                ng = mid;
            }
        }

        return ok;
    }

    /// <summary>
    /// <para>二分探索</para>
    /// <para>渡されたラムダ式の条件を満たすものの中で、一番右側のもの(インデックスが大きい)</para>
    /// </summary>
    /// <typeparam name="T">IEnumerable</typeparam>
    /// <param name="solve"></param>
    /// <returns>一番右側のインデックス</returns>
    public static int RightBinarySearchIndex<T>(this IEnumerable<T> self, Func<T, bool> solve)
    {
        int ng = self.Count();
        int ok = -1;

        while (Math.Abs(ok - ng) > 1)
        {
            int mid = (ok + ng) / 2;

            if (solve(self.ElementAt(mid)))
            {
                ok = mid;
            }
            else
            {
                ng = mid;
            }
        }

        return ok;
    }

    /// <summary>
    /// リストを埋める
    /// </summary>
    /// <typeparam name="T">型T</typeparam>
    /// <param name="self">リスト</param>
    /// <param name="func">(index) => T</param>
    /// <returns>リストの参照</returns>
    public static IList<T> Fill<T>(this IList<T> self, Func<int, T> func)
    {
        for (int i = 0; i < self.Count; i++)
        {
            self[i] = func(i);
        }

        return self;
    }

    /// <summary>
    /// リストを埋める
    /// </summary>
    /// <typeparam name="T">型T</typeparam>
    /// <param name="self">リスト</param>
    /// <param name="value">型Tの値</param>
    /// <returns>リストの参照</returns>
    public static IList<T> Fill<T>(this IList<T> self, T value)
    {
        for (int i = 0; i < self.Count; i++)
        {
            self[i] = value;
        }

        return self;
    }
}

/// <summary>
/// Int拡張
/// </summary>
public static class IntExtensiton
{
    public static int BitCount(this int bit, int digit = 32)
    {
        int count = 0;
        for (int i = (digit - 1); i >= 0; i--)
        {
            if (bit.GetBit(i)) count++;
        }
        return count;
    }

    public static bool GetBit(this int bit, int digit)
    {
        int mask = (1 << digit);
        return (bit & mask) == mask;
    }

    public static int SetBit(this int bit, int digit)
    {
        return (bit | (1 << digit));
    }

    public static string BitToString(this int bit, int digit = 32)
    {
        StringBuilder sb = new StringBuilder();

        for(int i = (digit - 1); i >= 0; i--)
        {
            sb.Append(bit.GetBit(i) ? "1" : "0");
        }

        return sb.ToString();
    }
}

/// <summary>
/// String拡張
/// </summary>
public static class StringExtensiton
{
    public static int Int(this string str)
    {
        return int.Parse(str);
    }

    public static long Long(this string str)
    {
        return long.Parse(str);
    }

    public static double Double(this string str)
    {
        return double.Parse(str);
    }
}
