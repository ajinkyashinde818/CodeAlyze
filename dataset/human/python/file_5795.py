import std.stdio, std.conv, std.string, std.array, std.range, std.algorithm, std.container;
import std.math, std.random, std.bigint, std.datetime, std.format;
void main(string[] args){ if(args.length > 1) if(args[1] == "-debug") DEBUG = 1; solve(); }
void log()(){ writeln(""); } void log(T, A ...)(T t, lazy A a){ if(DEBUG) write(t, " "), log(a); } bool DEBUG = 0;
string read(){ static string[] ss; while(!ss.length) ss = readln.chomp.split; string res = ss[0]; ss.popFront; return res; }
T rtype(T)(){ return read.to!T; } alias rint = rtype!int, rlong = rtype!long, rreal = rtype!real;
T[] rtypes(T)(int n){ return n.iota.map!(i => rtype!T()).array; } alias rint = rtypes!int, rlong = rtypes!long, rreal = rtype!real;
// ----- ----- ----- ----- ----- ----- ----- ----- ----- ----- ----- ----- //
void solve(){
	int n = rint;
	int[] as = rint(n).map!(x => x - 1).array;
	long[] bs = rlong(n);
	long[] cs =rlong(n - 1);
	
	long ans;
	foreach(i; 0 .. n){
		ans += bs[as[i]];
		if(i < n - 1 && as[i + 1] == as[i] + 1) ans += cs[as[i]];
		log("i:", i, "ans:", ans);
	}
	
	ans.writeln;
}
