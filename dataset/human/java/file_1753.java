using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AtCorder
{
	public class Program
	{
		const long MOD = 1000000007;

		static void Main(string[] args)
		{
			int n = int.Parse(Console.ReadLine());
			string s = Console.ReadLine();
			int[] nums = new int[26];
			for (int i = 0; i < n; i++) {
				nums[s[i] - 'a']++;
			}

			int[] doubles = nums.Where(x => x > 1).ToArray();
			if (doubles.Length == 0) {
				long ans = ModInt.Pow(2, n).num - 1;
				Console.WriteLine(ans);
			} else {
				long removes = doubles.Select(x => x).Sum();
				long remains = n - removes;
				long ans = ModInt.Pow(2, remains).num;
				for (int i = 0; i < doubles.Count(); i++) {
					ans = (ans * (doubles[i] + 1)) % MOD;
				}

				Console.WriteLine(ans - 1);
			}
		}
	}

	struct ModInt
	{
		/// <summary>
		/// 剰余を取る値．
		/// </summary>
		public const long Mod = (int)1e9 + 7;

		/// <summary>
		/// 実際の数値．
		/// </summary>
		public long num;
		/// <summary>
		/// 値が <paramref name="n"/> であるようなインスタンスを構築します．
		/// </summary>
		/// <param name="n">インスタンスが持つ値</param>
		/// <remarks>パフォーマンスの問題上，コンストラクタ内では剰余を取りません．そのため，<paramref name="n"/> ∈ [0,<see cref="Mod"/>) を満たすような <paramref name="n"/> を渡してください．このコンストラクタは O(1) で実行されます．</remarks>
		public ModInt(long n) { num = n; }
		/// <summary>
		/// このインスタンスの数値を文字列に変換します．
		/// </summary>
		/// <returns>[0,<see cref="Mod"/>) の範囲内の整数を 10 進表記したもの．</returns>
		public override string ToString() { return num.ToString(); }
		public static ModInt operator +(ModInt l, ModInt r) { l.num += r.num; if (l.num >= Mod) l.num -= Mod; return l; }
		public static ModInt operator -(ModInt l, ModInt r) { l.num -= r.num; if (l.num < 0) l.num += Mod; return l; }
		public static ModInt operator *(ModInt l, ModInt r) { return new ModInt(l.num * r.num % Mod); }
		public static implicit operator ModInt(long n) { n %= Mod; if (n < 0) n += Mod; return new ModInt(n); }

		/// <summary>
		/// 与えられた 2 つの数値からべき剰余を計算します．
		/// </summary>
		/// <param name="v">べき乗の底</param>
		/// <param name="k">べき指数</param>
		/// <returns>繰り返し二乗法により O(N log N) で実行されます．</returns>
		public static ModInt Pow(ModInt v, long k) { return Pow(v.num, k); }

		/// <summary>
		/// 与えられた 2 つの数値からべき剰余を計算します．
		/// </summary>
		/// <param name="v">べき乗の底</param>
		/// <param name="k">べき指数</param>
		/// <returns>繰り返し二乗法により O(N log N) で実行されます．</returns>
		public static ModInt Pow(long v, long k)
		{
			long ret = 1;
			for (k %= Mod - 1; k > 0; k >>= 1, v = v * v % Mod)
				if ((k & 1) == 1)
					ret = ret * v % Mod;
			return new ModInt(ret);
		}
		/// <summary>
		/// 与えられた数の逆元を計算します．
		/// </summary>
		/// <param name="v">逆元を取る対象となる数</param>
		/// <returns>逆元となるような値</returns>
		/// <remarks>法が素数であることを仮定して，フェルマーの小定理に従って逆元を O(log N) で計算します．</remarks>
		public static ModInt Inverse(ModInt v) { return Pow(v, Mod - 2); }
	}

	
}
