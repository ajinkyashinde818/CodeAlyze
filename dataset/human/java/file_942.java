using System;
using System.Linq;
using System.Collections.Generic;

namespace ConsoleApp2
{


    public class Program
    {

        static long mod = (long)Math.Pow(10, 9) + 7;

        public static void Main(string[] args)
        {
            int[] NR = Read(Console.ReadLine());
            int N = NR[0];
            int R = NR[1];
            int ans = -1;

            if (N >= 10) ans = R;
            else
            {
                ans = R + 100 * (10 - N);
            }

            Console.WriteLine(ans);
            Console.ReadLine();
        }


        static long[] BinarySearchSpace(long[] sortedArray,long value)
        {
            long min = 0;
            long max = sortedArray.Length;
            long mid = (min + max) / 2;

            if (value <= sortedArray[0]) return new long[2] { -1, 0 };
            if (value >= sortedArray[sortedArray.Length-1]) return new long[2] { sortedArray.Length-1,sortedArray.Length };

            while (max<min)
            {
                if (sortedArray[mid] > value) max = mid;
                else if (sortedArray[mid] < value) min = mid;
                else return new long[2] { mid, mid + 1 };

                if (min == max - 1) return new long[2] { min, max };
            }
            return null;
        }


        static Dictionary<long,long> FindElements(long N)
        {
            long curN = N;
            Dictionary<long, long> elements = new Dictionary<long, long>();
           
            for (int i = 2; i <= (long)Math.Sqrt(N); i++)
            {
                while (curN%i==0)
                {
                    curN /= i;
                    if (elements.ContainsKey(i)) elements[i]++;
                    else elements.Add(i, 1);
                }
            }
            if(curN!=1)elements.Add(curN, 1);
            return elements;
        }

        public static long GetInv(long a, long mod)
        {
            return PowerMod(a, mod - 2, mod);
        }

        public static long Combination(long a, long b, long mod)
        {
            long numerator = Factorial(a, mod);
            long denominator = (Factorial(b, mod) * Factorial(a - b, mod)) % mod;

            return (numerator * GetInv(denominator, mod)) % mod;
        }

        public static long Factorial(long n, long mod)
        {
            if (n == 0) return 1;
            if (n == 1) return 1;
            long ans = n;
            for (int i = 2; i < n; i++)
            {
                ans = (ans * i) % mod;
            }

            return ans;
        }




        private static long PowerMod(long a, long n, long mod)
        {
            if (n == 1) return a;

            long p = PowerMod(a, n / 2, mod);
            if (n % 2 == 1) return ((p * p) % mod * a) % mod;
            else return (p * p) % mod;
        }

        public static class Comb
        {
            public static IEnumerable<T[]> Enumerate<T>(IEnumerable<T> items, int k, bool withRepetition)
            {
                if (k == 1)
                {
                    foreach (var item in items)
                        yield return new T[] { item };
                    yield break;
                }
                foreach (var item in items)
                {
                    var leftside = new T[] { item };

                    // item よりも前のものを除く （順列と組み合わせの違い)
                    // 重複を許さないので、unusedから item そのものも取り除く
                    var unused = withRepetition ? items : items.SkipWhile(e => !e.Equals(item)).Skip(1).ToList();

                    foreach (var rightside in Enumerate(unused, k - 1, withRepetition))
                    {
                        yield return leftside.Concat(rightside).ToArray();
                    }
                }
            }
        }

        public class BFSClass
        {
            /// <summary>
            /// 1...道、2...障害物(0は未知)
            /// </summary>
            /// <param name="map"></param>
            public BFSClass(int[][] map)
            {
                Map = map;
            }

            private class TileFrom
            {
                public TileFrom(int[] thisTile, int[] from)
                {
                    ThisTile = thisTile;
                    From = from;
                }
                public int[] ThisTile { get; }
                public int[] From { get; }
            }

            public int[][] Map { get; }

            //調べる予定の位置を入れる
            Queue<int[]> search = new Queue<int[]>();

            //調べ終わった位置
            List<TileFrom> done = new List<TileFrom>();

            /// <summary>
            /// 
            /// </summary>
            /// <param name="map"></param>
            public int BFS(int[] startPos, int[] goalPos)
            {
                done.Add(new TileFrom(startPos, null));

                //現在の位置
                int[] currentPos = startPos;

                return StartBFS(0,currentPos, goalPos);
            }

            /// <summary>
            /// 終わったらtrue
            /// </summary>
            /// <param name="currentPos"></param>
            /// <param name="goalPos"></param>
            private int StartBFS(int currentCount,int[] currentPos, int[] goalPos)
            {
                if (currentPos.SequenceEqual(goalPos)) return currentCount;

                List<int[]> around = GetAroundTile(currentPos);
                foreach (var item in around)
                {
                    if (!done.Exists(i => i.ThisTile.SequenceEqual(item)))
                    {
                        done.Add(new TileFrom(item, currentPos));
                        search.Enqueue(item);
                        Console.WriteLine(item[0] + "," + item[1] + "を調べます");
                    }
                    else
                    {
                        Console.WriteLine(item[0] + "," + item[1] + "は済んでいます");
                    }
                }

                while (search.Count > 0)
                {
                    var nextStartPos = search.Dequeue();
                    if (Map[nextStartPos[0]][nextStartPos[1]] == 1)
                    {
                        return StartBFS(currentCount+1,nextStartPos, goalPos);
                    }
                }

                return 0;
            }

            private List<int[]> GetAroundTile(int[] pos)
            {
                List<int[]> ans = new List<int[]>();
                int[][] deltas = {  new int[2] { 0, 1 },
                                new int[2] { 1, 0 },
                                new int[2] { 0, -1 },
                                new int[2] { -1, 0 } };

                foreach (var delta in deltas)
                {
                    int[] newPos = { pos[0] + delta[0], pos[1] + delta[1] };
                    if (OnMap(newPos)) ans.Add(newPos);
                }
                return ans;
            }

            private bool OnMap(int[] pos)
            {
                if (pos[0] >= 0 && pos[0] < Map.Length)
                {
                    if (pos[1] >= 0 && pos[1] < Map[0].Length)
                    {
                        return true;
                    }
                }
                return false;
            }

            private int FindRoot(int[] goalPos)
            {
                Stack<int[]> root = new Stack<int[]>();
                root.Push(goalPos);

                TileFrom f = done.Find(i => i.ThisTile[0] == goalPos[0] && i.ThisTile[1] == goalPos[1]);
                while (true)
                {
                    root.Push(f.From);
                   // Console.WriteLine("[" + f.ThisTile[0] + "," + f.ThisTile[1] + "]" + "から[" + f.From[0] + "," + f.From[1] + "]");

                    TileFrom test = done.Find(i => i.ThisTile[0] == f.From[0] && i.ThisTile[1] == f.From[1]);

                    if (test.From == null) break;
                    f = test;
                }
                //while (root.Count > 0)
                //{
                //    int[] r = root.Pop();
                //    Console.WriteLine("[" + r[0] + "," + r[1] + "]");
                //}
                return root.Count - 1;
            }
        }


      

        static long Com(int n, int m)
        {
            if (m == 0 || m == n) return 1;

            if (n < m) return 0;

            int[] a = new int[m];

            for (int i = 0; i < m; i++)
            {
                a[i] = n - i;
            }
            for (int i = 1; i <= m; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    if (a[j] % i == 0)
                    {
                        a[j] /= i;
                        break;
                    }
                }
            }

            long ans = 1;
            for (int i = 0; i < m; i++)
            {
                ans *= a[i];
                ans %= mod;
            }
            return ans;
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


        private static bool S(int[] data,int K ,int l ,int x)
        {
            int sum = 0;
            int max = Math.Min(x+1, data.Length);
            for (int i = l; i < max; i++)
            {
                sum += data[i];
            }
            Console.WriteLine(sum);
            return sum>=K;
        }


        public static IEnumerable<T[]> Enumerate<T>(IEnumerable<T> items)
        {
            if (items.Count() == 1)
            {
                yield return new T[] { items.First() };
                yield break;
            }
            foreach (var item in items)
            {
                var leftside = new T[] { item };
                var unused = items.Except(leftside);
                foreach (var rightside in Enumerate(unused))
                {
                    yield return leftside.Concat(rightside).ToArray();
                }
            }
        }




        private static string ReplaceOneChar(string S, int index, string newS)
        {
            string s1 = S.Substring(0, index - 1);
            string s2 = S.Substring(index);
            return s1 + newS + s2;
        }

        private static bool PartialSum(int target, int[] Ns)
        {
            //if (target == 0) return true;
            bool[][] ps = new bool[Ns.Length + 1][];

            //i=0では、どんなWに対してもfalse
            ps[0] = new bool[target+1];
            for (int i = 0; i < ps[0].Length; i++) ps[0][i] = false;

            ps[0][0] = true;


            //考慮に入れるitemを、前から順に追加していく
            for (int i = 0; i < Ns.Length; i++)
            {
                //初期化
                ps[i + 1] = new bool[target+1];

                for (int t = 0; t <= target; t++)
                {
                    if (t >= Ns[i]) ps[i + 1][t] = ps[i][t - Ns[i]] || ps[i][t];
                    else ps[i + 1][t]=ps[i][t];
                }
            }

            return ps[Ns.Length][target];
        }

        /// <summary>
        /// 引数は、W(重さ制限)、items[重さ][価値]
        /// </summary>
        /// <param name="W"></param>
        /// <param name="items"></param>
        /// <returns></returns>
        private static int DP(int W,int[][] items)
        {
            //データ
            int[][] dp = new int[items.Length+1][];

            //i=0では、どんなWに対しても0
            dp[0] = new int[W + 1];

            //考慮に入れるitemを、前から順に追加していく
            for (int i = 0; i < items.Length; i++)
            {
                //初期化
                dp[i+1] = new int[W + 1];

                for (int w = 0; w <= W; w++)
                {
                    if (w >= items[i][0]) dp[i + 1][w] = Math.Max(dp[i][w - items[i][0]]+items[i][1], dp[i][w]);
                    else dp[i + 1][w] = dp[i][w];
                }
            }
            return dp[items.Length][W];
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
