using System;
using System.Linq;
using System.Collections.Generic;
using System.Diagnostics;
using Debug = System.Diagnostics.Trace;
using SB = System.Text.StringBuilder;
using static System.Math;
using Number = System.Int32;
using System.Numerics;
using static System.Numerics.BigInteger;
namespace Program {
	public class Solver {
		Random rnd = new Random(0);
		public void Solve() {
			var k = ri;
			var n = ri;
			var a = Enumerate(n, x => ri);
			var mi = 0;
			for (int i = 0; i < n - 1; i++)
				mi = Max(mi, a[i + 1] - a[i]);
			mi = Max(mi, k - a.Last() + a.First());
			Console.WriteLine(k - mi);

		}
		const long INF = 1L << 60;
		static int[] dx = { -1, 0, 1, 0 };
		static int[] dy = { 0, 1, 0, -1 };
		int ri { get { return sc.Integer(); } }
		long rl { get { return sc.Long(); } }
		double rd { get { return sc.Double(); } }
		string rs { get { return sc.Scan(); } }
		public IO.StreamScanner sc = new IO.StreamScanner(Console.OpenStandardInput());

		static T[] Enumerate<T>(int n, Func<int, T> f) {
			var a = new T[n];
			for (int i = 0; i < a.Length; ++i) a[i] = f(i);
			return a;
		}
		static public void Swap<T>(ref T a, ref T b) { var tmp = a; a = b; b = tmp; }
	}
}

#region main
static class Ex {
	static public string AsString(this IEnumerable<char> ie) { return new string(ie.ToArray()); }
	static public string AsJoinedString<T>(this IEnumerable<T> ie, string st = " ") {
		return string.Join(st, ie);
	}
	static public void Main() {
		Console.SetOut(new Program.IO.Printer(Console.OpenStandardOutput()) { AutoFlush = true });
		var solver = new Program.Solver();
		//* 
		var t = new System.Threading.Thread(solver.Solve, 50000000);
		//t.Start();
		//t.Join();
		//*/
		solver.Solve();
		Console.Out.Flush();
	}
}
#endregion
#region Ex
namespace Program.IO {
	using System.IO;
	using System.Text;
	using System.Globalization;

	public class Printer : StreamWriter {
		public override IFormatProvider FormatProvider { get { return CultureInfo.InvariantCulture; } }
		public Printer(Stream stream) : base(stream, new UTF8Encoding(false, true)) { }
	}

	public class StreamScanner {
		public StreamScanner(Stream stream) { str = stream; }

		public readonly Stream str;
		private readonly byte[] buf = new byte[1024];
		private int len, ptr;
		public bool isEof = false;
		public bool IsEndOfStream { get { return isEof; } }

		private byte read() {
			if (isEof) return 0;
			if (ptr >= len) {
				ptr = 0;
				if ((len = str.Read(buf, 0, 1024)) <= 0) {
					isEof = true;
					return 0;
				}
			}
			return buf[ptr++];
		}

		public char Char() {
			byte b = 0;
			do b = read(); while ((b < 33 || 126 < b) && !isEof);
			return (char)b;
		}
		public string Scan() {
			var sb = new StringBuilder();
			for (var b = Char(); b >= 33 && b <= 126; b = (char)read()) sb.Append(b);
			return sb.ToString();
		}
		public string ScanLine() {
			var sb = new StringBuilder();
			for (var b = Char(); b != '\n' && b != 0; b = (char)read()) if (b != '\r') sb.Append(b);
			return sb.ToString();
		}
		public long Long() { return isEof ? long.MinValue : long.Parse(Scan()); }
		public int Integer() { return isEof ? int.MinValue : int.Parse(Scan()); }
		public double Double() { return isEof ? double.NaN : double.Parse(Scan(), CultureInfo.InvariantCulture); }
	}
}

#endregion

#region ModInt
/// <summary>
/// [0,<see cref="Mod"/>) までの値を取るような数
/// </summary>
public struct ModInt {
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
	public static ModInt Pow(long v, long k) {
		long ret = 1;
		for (k %= Mod - 1; k > 0; k >>= 1, v = v * v % Mod)
			if ((k & 1) == 1) ret = ret * v % Mod;
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
#endregion
