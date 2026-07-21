using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System;
using System.Collections.Generic;
using System.Linq;

namespace ClassLibrary1
{
    public class ListNode
    {
        public int val;
        public ListNode next;
        public ListNode(int x) { val = x; }
    }


    public class Class1
    {
        static Dictionary<Tuple<long, long>, long> dic = new Dictionary<Tuple<long, long>, long>();

        static long mod = 1000000007;
        static long[] factorial = new long[1000001];
        static long[] invFactorial = new long[1000001];

        private static void calcFanctorial(long N)
        {
            factorial[0] = 1;
            for (int i = 1; i < N + 1; i++)
            {
                factorial[i] = factorial[i - 1] * i;
                factorial[i] %= mod;
            }
            invFactorial[N] = inv(factorial[N]);
            for (int i = (int)N; i > 0; i--)
            {
                invFactorial[i - 1] = invFactorial[i] * i % mod;
            }

        }

        static void Main(string[] args)
        {
            var S = ReadString();
            var Q = ReadLong();

//            var res = S.ToCharArray();
            bool reverse = false;
            var pre = new char[200000];
            var precnt = 0;
            var post = new char[200000];
            var postcnt = 0;

            var QQQ = new string[Q][];
            for(long i=0; i<Q; i++)
            {
                QQQ[i] = ReadStringArr();
            }

            for (int i=0; i<Q; i++)
            {
                if(QQQ[i][0] == "1")
                {
                    reverse = !reverse;
                }else
                {
                    if(reverse ^ (QQQ[i][1] == "1"))
                    {
                        //    res = QQ[2] + res;
                        pre[precnt] = QQQ[i][2][0];
                        precnt++;
                    }
                    else
                    {
                        //                        res = res + QQ[2];
                        post[postcnt] = QQQ[i][2][0];
                        postcnt++;
                    }
                }
            }
            var res = "";
            var xx = S.ToCharArray();
            var pr = new char[precnt];
            var pp = new char[postcnt];
            if (!reverse)
            {
                Array.Copy(pre, 0, pr, 0, precnt);
                Array.Reverse(pr);
                res += new string(pr);

                res += new string(xx);

                Array.Copy(post, 0, pp, 0, postcnt);
                res += new string(pp);

                Console.WriteLine(res);
                return;

            }
            /*
            for (int i = 0; i < postcnt; i++)
            {
                res += post[postcnt - 1 - i];
            }
            for (int i = 0; i < xx.Length; i++)
            {
                res += xx[xx.Length - i - 1];
            }
            for (int i = 0; i < precnt; i++)
            {
                res += pre[i];
            }
            */
            Array.Copy(post, 0, pp, 0, postcnt);

            Array.Reverse(pp);
            res += new string(pp);

            Array.Reverse(xx);
            res += new string(xx);


            Array.Copy(pre, 0, pr, 0, precnt);
            res += new string(pr);

            Console.WriteLine(res);

        }

        private static void rec(long b, Relation[] rltn, long f, HashSet<long> pass)
        {
           // var res = new HashSet<long>();
            foreach (var ff in rltn[f].friends)
            {
                if (!rltn[b].block.Contains(ff) && !rltn[b].friends.Contains(ff) && b != ff)
                {
                    //res.Add(ff);
                    pass.Add(ff);
                    rec(b, rltn, ff, pass);
                    
                }
            }
//            return res;
        }

        class Relation
        {
            public HashSet<long> friends = new HashSet<long>();
            public HashSet<long> block = new HashSet<long>();
        }

        static long bin(long a, long x, long n)
        {
            long y = a;
            long res = 1;
            while(x>0)
            {
                if (x%2 == 1){
                    res = res * y % n;
                }
                x /= 2;
                y = y * y % n;
            }
            return res ;
        }

        int cmp(string a, string b)
        {
            for (var i = 0; i < Math.Min(a.Length, b.Length); i++)
                if (a[i] < b[i]) return -1;
                else if (a[i] > b[i]) return 1;
            if (a.Length == b.Length) return 0;
            if (a.Length > b.Length) return 1;
            else return -1;
        }

        private static long nCm(long n, long m)
        {
            if (n < m) return 0;
            if (m < 0) return 0;

            return (factorial[n] * invFactorial[m] % mod) * invFactorial[n - m] % mod;
        }

        private static long nCm2(long n, long m)
        {
            if (n < m) return 0;
            if (m < 0) return 0;

            long res = 1;
            for(long i = n; i>n-m; i--)
            {
                res *= i;
                res %= mod;
            }

            return res * invFactorial[m] % mod;
        }

        public static long pow(long a, long b, long mod)
        {
            a %= mod;

            if (b <= 0) return 1;
            var t = pow(a, b / 2, mod);
            if ((b & 1) == 0) return t * t % mod;
            return t * t % mod * a % mod;
        }

        public static long Lcm(long a, long b)
        {
            return a * b % mod * inv(Gcd(a, b)) % mod;
        }

        public static long Lcm(long[] a)
        {
            List<long> vect = new List<long>();
            long lcm = 1;
            for (int i = 0; i < a.Count(); i++)
            {
                var factor = a[i] / GcdVector(vect, a[i]);
                vect.Add(factor);
                lcm = lcm * factor % mod;
            }
            return lcm;
        }

        static long GcdVector(List<long> a, long b)
        {
            long ma = 1;
            for (int i = 0; i < a.Count; i++)
                ma = ma * a[i] % b;
            return Gcd(b, ma);
        }

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

        public static long pow(long a, long b) => pow(a, b, mod);
        public static long inv(long a) => pow(a, mod - 2);

        private static char[][] ReadCharMatrix(long h)
        {
            char[][] mtx = new char[h][];
            for (int i = 0; i < h; i++)
            {
                var s = ReadString();
                mtx[i] = s.ToCharArray();
            }
            return mtx;
        }

        private static int[][] CreateIntMatrix(long h, long w)
        {
            int[][] mtx = new int[h][];
            for (int i = 0; i < h; i++)
            {
                mtx[i] = new int[w];
            }
            return mtx;
        }


        private static string ReadString()
        {
            return Console.ReadLine();
        }
        private static string[] ReadStringArr()
        {
            return Console.ReadLine().Split(' ');
        }
        private static long ReadLong()
        {
            return long.Parse(Console.ReadLine());
        }
        private static long[] ReadLongArr()
        {
            string[] s = ReadStringArr();
            long[] l = new long[s.Length];
            for (int i = 0; i < l.Length; i++)
            {
                l[i] = long.Parse(s[i]);
            }

            return l;
        }
    }
    class StringComparator2 : IComparer<string>
    {
        int IComparer<string>.Compare(string a, string b)
        {
            int length = Math.Min(a.Length, b.Length);
            //Console.WriteLine("Comparing with length {0}", length);
            for (int i = 0; i < length; i++)
            {
                if (a[i] < b[i])
                {
                    //Console.WriteLine("returning -1");
                    return -1;
                }
                else if (a[i] > b[i]) return 1;
            }
            if (a.Length < b.Length) return -1;
            if (a.Length > b.Length) return 1;

            //Console.WriteLine("Why are we at the end?");
            return 0;
        }
    }

    public class PriorityQueue<T> where T : IComparable
    {
        private IComparer<T> _comparer = null;
        private int _type = 0;

        private T[] _heap;
        private int _sz = 0;

        private int _count = 0;

        /// <summary>
        /// Priority Queue with custom comparer
        /// </summary>
        public PriorityQueue(int maxSize, IComparer<T> comparer)
        {
            _heap = new T[maxSize];
            _comparer = comparer;
        }

        /// <summary>
        /// Priority queue
        /// </summary>
        /// <param name="maxSize">max size</param>
        /// <param name="type">0: asc, 1:desc</param>
        public PriorityQueue(int maxSize, int type = 0)
        {
            _heap = new T[maxSize];
            _type = type;
        }

        private int Compare(T x, T y)
        {
            if (_comparer != null) return _comparer.Compare(x, y);
            return _type == 0 ? x.CompareTo(y) : y.CompareTo(x);
        }

        public void Push(T x)
        {
            _count++;

            //node number
            var i = _sz++;

            while (i > 0)
            {
                //parent node number
                var p = (i - 1) / 2;

                if (Compare(_heap[p], x) <= 0) break;

                _heap[i] = _heap[p];
                i = p;
            }

            _heap[i] = x;
        }

        public T Pop()
        {
            _count--;

            T ret = _heap[0];
            T x = _heap[--_sz];

            int i = 0;
            while (i * 2 + 1 < _sz)
            {
                //children
                int a = i * 2 + 1;
                int b = i * 2 + 2;

                if (b < _sz && Compare(_heap[b], _heap[a]) < 0) a = b;

                if (Compare(_heap[a], x) >= 0) break;

                _heap[i] = _heap[a];
                i = a;
            }

            _heap[i] = x;

            return ret;
        }

        public int Count()
        {
            return _count;
        }

        public T Peek()
        {
            return _heap[0];
        }

        public bool Contains(T x)
        {
            for (int i = 0; i < _sz; i++) if (x.Equals(_heap[i])) return true;
            return false;
        }

        public void Clear()
        {
            while (this.Count() > 0) this.Pop();
        }

        public IEnumerator<T> GetEnumerator()
        {
            var ret = new List<T>();

            while (this.Count() > 0)
            {
                ret.Add(this.Pop());
            }

            foreach (var r in ret)
            {
                this.Push(r);
                yield return r;
            }
        }

        public T[] ToArray()
        {
            T[] array = new T[_sz];
            int i = 0;

            foreach (var r in this)
            {
                array[i++] = r;
            }

            return array;
        }
    }


}
