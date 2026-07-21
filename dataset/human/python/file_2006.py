import std.stdio, std.string, std.conv;
import std.typecons;
import std.algorithm, std.array, std.range, std.container;
import std.math;

// mod must be a prime number
struct Mod(uint mod) if (mod < int.max) {
	import std.conv : to;
	
	uint n;
	this(int m)  { this(long(m)); }
	this(long m) { this.n = m >= 0L ? cast(uint)(m % mod) : cast(uint)(m % mod + mod); }
	this(ulong m) { this.n = cast(uint)(m % mod); }
	
	static auto normalize_(uint x) { return (x>=mod)? x-mod : x; }
	static auto make_(uint x) { Mod!mod m; m.n = x; return m; }
	
	auto opBinary(string op:"+")(Mod b)  const { return make_(normalize_(n+b.n)); }
	auto opBinary(string op:"-")(Mod b)  const { return make_(normalize_(n+mod-b.n)); }
	auto opBinary(string op:"*")(Mod b)  const { return make_( ((ulong(n)*b.n) % mod).to!uint ); }
	auto opBinary(string op:"^^")(Mod b) const {
		//return make_( ( n ^^ ( b.n % (mod-1) ) % mod ).to!uint );
		auto accumulater = make_(this.n), result = make_(1);
		ulong order = b.n % (mod-1), pwr2 = 1;
		foreach (i; 0 .. 33) {
			if (pwr2 > order) break;
			if ((order & pwr2) != 0) result *= accumulater;
			accumulater *= accumulater, pwr2 *= 2;
		}
		return result;
	}
	static Mod inv(Mod x) { return x^^(mod-2); }
	auto opBinary(string op:"/")(Mod b)  const { return this*inv(b); }
	auto opUnary(string op: "-")() const { return make_(normalize_(mod-this.n )); }
	auto opOpAssign(string op)(Mod b) if (op == "+" || op == "-" || op == "*" || op == "/" || op == "^^") { return mixin("this=this"~op~"b"); }
	
	auto opBinary(string op)(long b) const if (op == "+" || op == "-" || op == "*" || op == "/" || op == "^^") {
		auto m = Mod!mod(b); return mixin("this"~op~"m");
	}
	auto opUnary(string op)(long b) const if (op == "-") {
		auto m = Mod!mod(b); return mixin(op~"m");
	}
	auto opOpAssign(string op)(long b) if (op == "+" || op == "-" || op == "*" || op == "/" || op == "^^") {
		auto m = Mod!mod(b); return mixin("this"~op~"=m");
	}
	
	auto opAssign(ulong b) { n = cast(uint)(b%mod); return this; }
	auto opAssign(long b)  { n = (b < 0) ? cast(uint)(b%mod + mod) : cast(uint)(b%mod); return this; }
	auto opAssign(int b)   { return opAssign(long(b)); }
	
	
	string toString() const { return n.to!string; }
}

alias Int = Mod!(10^^9+7);

Int comb(ulong n, ulong k) {
	//writeln("(",n, ", ", k, ")");
	if (k == 0 || n == k) return Int(1);
	k = k < n-k ? k : n-k;
	auto result = Int(1);
	foreach (i; n-k+1 .. n+1) { result *= i; }
	foreach (i; 2 .. k+1) { result /= i; }
	return result;
}

void main() {
	auto data = readln.split.to!(int[]);
	auto N = data[0];
	auto S = readln.split[0];
	
	Int ans = 1;
	
	foreach (c; 'a' .. 'z'+1) {
		ans *= (S.count(c) +1);
	}
	(ans-1).writeln;
}
