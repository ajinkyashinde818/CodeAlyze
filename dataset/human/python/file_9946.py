import std.stdio, std.conv, std.string, std.array, std.range, std.algorithm, std.container;
import std.math, std.random, std.bigint, std.datetime, std.format;
void main(string[] args){ if(args.length > 1) if(args[1] == "-debug") DEBUG = 1; solve(); }
void log()(){ writeln(""); } void log(T, A ...)(T t, lazy A a){ if(DEBUG) write(t, " "), log(a); } bool DEBUG = 0; 
string rstring(){ static string[] ss; while(!ss.length) ss = readln.chomp.split; string res = ss[0]; ss.popFront; return res; }
T rtype(T)(){ return rstring.to!T; } alias rint = rtype!int, rlong = rtype!long, rreal = rtype!real;
T[] rtypes(T)(int n){ return n.iota.map!(i => rtype!T()).array; } alias rint = rtypes!int, rlong = rtypes!long, rreal = rtypes!real;
T[][] rtypess(T)(int n, int m){ return n.iota.map!(i => rtypes!T(m)).array; } alias rint = rtypess!int, rlong = rtypess!long, rreal = rtypess!real;
T chmin(T)(ref T x, T y){ if(x > y) x = y; return x; } T chmax(T)(ref T x, T y){ if(x < y) x = y; return x; }

// ----- ----- ----- ----- ----- ----- ----- ----- ----- ----- ----- ----- //

void solve(){
	int a = rint, b = rint;
	lcm(a, b).writeln;
}
/// 最大公約数。最大の公約数。
/// 例 gcd(12, -18) = 6, gcd(-12, -18) = 6, gcd(12, 0) = 12, gcd(0, 0) = 0
/// ※本当は gcd(0, 0) は存在しないが便宜上 0 を返している
long gcd(long a, long b){
	if(a < 0) a = -a;
	if(b == 0) return a;
	if(b < 0) return gcd(a, -b);
	if(a % b == 0) return b;
	if(a < b) return gcd(b, a);
	else return gcd(b, a % b);
}

/// 最小公倍数。0以上で最小の公倍数。
/// 例 lcm(12, -18) = 36, lcm(-12, -18) = 36, lcm(12, 0) = 36, lcm(0, 0) = 0
long lcm(long a, long b){
	if(a < 0) a = -a; if(b < 0) b = -b;
	if(a == 0 && b == 0) return 0;
	return (a / gcd(a, b) * b);
}
