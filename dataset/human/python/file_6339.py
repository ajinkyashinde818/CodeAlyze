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
	long n = rlong;
	if(n % 2) "0".writeln;
	else{
		long a;
		for(long m = 5; m <= n; m *= 5) a += n / (2 * m);
		a.writeln;
	}
}

/*
 nが奇数のときは0
 nが偶数のときはn以下の偶数の5の倍数の個数（重複度込み）（2はふんだんにあるので）
 それは
*/
