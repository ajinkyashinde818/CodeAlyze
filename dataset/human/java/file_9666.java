using System;
using System.Linq;
using System.Collections.Generic;
using Debug = System.Diagnostics.Trace;
using SB = System.Text.StringBuilder;
using static System.Math;
using static Program.IO.Scanner;
using Number = System.Int64;
using System.Numerics;

#region IO
namespace Program.IO {
	using System.IO;
	using System.Text;
	using System.Globalization;

	public class Printer : StreamWriter {
		public override IFormatProvider FormatProvider { get { return CultureInfo.InvariantCulture; } }
		public Printer(Stream stream) : base(stream, new UTF8Encoding(false, true)) { }
	}
	static public class Scanner {
		public static StreamScanner sc = new StreamScanner(Console.OpenStandardInput());
		public static int ri => sc.Integer();
		public static long rl => sc.Long();
		public static string rs => sc.Scan();
		public static double rd => sc.Double();
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

#region main
static class Ex {
	static public string AsString(this IEnumerable<char> ie) { return new string(ie.ToArray()); }
	static public string AsJoinedString<T>(this IEnumerable<T> ie, string st = " ") {
		return string.Join(st, ie);
	}

	static public void Main() {
		Console.SetOut(new Program.IO.Printer(Console.OpenStandardOutput()) { AutoFlush = false });
		var solver = new Program.Solver();
		var t = new System.Threading.Thread(solver.Solve, 50000000);
		t.Start();
		t.Join();
		//*/
		//solver.Solve();
		Console.Out.Flush();
	}
}
#endregion

namespace Program {
	public class Solver {
		Random rnd = new Random(0);
		public void Solve() {
			var n = ri;
			var a = Enumerate(n, x => ri == ri);
			for (int i = 1; i < n - 1; i++)
				if (a[i - 1] && a[i] && a[i + 1]) {
					Console.WriteLine("Yes");
					return;
				}
			Console.WriteLine("No");
		}

		const long INF = 1L << 60;
		static int[] dx = { -1, 0, 1, 0 };
		static int[] dy = { 0, 1, 0, -1 };
		static T[] Enumerate<T>(int n, Func<int, T> f) {
			var a = new T[n]; for (int i = 0; i < a.Length; ++i) a[i] = f(i); return a;
		}
		static T[][] Enumerate<T>(int n, int m, Func<int, int, T> f) {
			return Enumerate(n, x => Enumerate(m, y => f(x, y)));
		}
		static public void Swap<T>(ref T a, ref T b) { var tmp = a; a = b; b = tmp; }
	}
}
