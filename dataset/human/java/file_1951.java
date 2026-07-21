using System;

namespace AtCoder.Problems
{
    public class ProblemAbc079C
    {
        public static void Main(string[] args)
        {
            var s = new Solve079C();
            s.Solve();
        }

        public class Scanner
        {
            private string[] _s;
            private int _i;
            private readonly char[] _separators = new char[] {' '};

            public Scanner()
            {
                _s = new string[0];
                _i = 0;
            }

            public string Next()
            {
                if (_i < _s.Length) return _s[_i++];
                string st = Console.ReadLine();
                while (st == "") st = Console.ReadLine();
                _s = st.Split(_separators, StringSplitOptions.RemoveEmptyEntries);
                if (_s.Length == 0) return Next();
                _i = 0;
                return _s[_i++];
            }

            public int NextInt() => int.Parse(Next());
            public long NextLong() => long.Parse(Next());
            public ulong NextULong() => ulong.Parse(Next());
            public double NextDouble() => double.Parse(Next());

            public int[] GetIntArray(int n, int add = 0)
            {
                int[] array = new int[n];
                for (int i = 0; i < n; i++)
                {
                    array[i] = NextInt() + add;
                }
                return array;
            }

            public long[] GetLongArray(int n, long add = 0)
            {
                long[] array = new long[n];
                for (int i = 0; i < n; i++)
                {
                    array[i] = NextLong() + add;
                }
                return array;
            }

            public double[] GetDoubleArray(int n, double add = 0)
            {
                double[] array = new double[n];
                for (int i = 0; i < n; i++)
                {
                    array[i] = NextDouble() + add;
                }
                return array;
            }
        }
    }

    public class Solve079C
    {
        public void Solve()
        {
            var cin = new ProblemAbc079C.Scanner();
            var d = cin.NextInt();
            var g = cin.NextInt();
            var p = new int[d];
            var c = new int[d];
            for (int i = 0; i < d; i++)
            {
                p[i] = cin.NextInt();
                c[i] = cin.NextInt();
            }

            var result = GetAnswer(d, g, p, c);
            Console.WriteLine(result);
        }

        public long GetAnswer(int d, int g, int[] p, int[] c)
        {
            var ans = long.MaxValue;
            for (uint flag = 0; flag < 1 << d; ++flag)
            {
                var sum = 0L;
                var count = 0L;
                for (int i = 0; i < d; i++)
                {
                    if ((flag & (1 << i)) != 0)
                    {
                        sum += (i + 1) * 100 * p[i] + c[i];
                        count += p[i];
                    }
                }

                if (sum >= g)
                {
                    ans = Math.Min(ans, count);
                    continue;
                }

                for (int i = d - 1; i >= 0; i--)
                {
                    if ((flag & (1 << i)) != 0) { continue; }

                    var remain = g - sum;
                    var point = (i + 1) * 100;
                    var cnt = remain / point;
                    if (remain % point != 0) { cnt++;}
                    
                    if (cnt < p[i])
                    {
                        ans = Math.Min(ans, count + cnt);
                        break;
                    }
                    cnt = p[i] - 1;
                    sum += point * cnt;
                    count += cnt;
                }
            }

            return ans;
        }
    }
}
