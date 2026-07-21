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
	char[] s = readln.chomp.to!(char[]);
	int n = s.length.to!int;
	int dir = 1;
	int len1, len2;
	int q = rint;
	char[] x1 = new char[](n + q), x2 = new char[](n + q);
	foreach(_; 0 .. q){
		int t = rint;
		if(t == 1) dir = 3 - dir;
		else if(t == 2){
			int f = rint;
			char[] c = rstring.to!(char[]);
			if(f == 1){
				if(dir == 1) x1[len1] = c[0], len1 ++;
				else x2[len2] = c[0], len2 ++;
			}
			else{
				if(dir == 1) x2[len2] = c[0], len2 ++;
				else x1[len1] = c[0], len1 ++;
			}
		}
		log("dir:", dir, "x1:", x1, "x2:", x2, "len1:", len1, "len2:", len2);
	}
	
	char[] ans = new char[](n + len1 + len2);
	if(dir == 1){
		int i = 0;
		foreach_reverse(c; x1[0 .. len1]) ans[i] = c, i ++;
		foreach(c; s) ans[i] = c, i ++;
		foreach(c; x2[0 .. len2]) ans[i] = c, i ++;
	}
	else{
		int i = 0;
		foreach_reverse(c; x2[0 .. len2]) ans[i] = c, i ++;
		foreach_reverse(c; s) ans[i] = c, i ++;
		foreach(c; x1[0 .. len1]) ans[i] = c, i ++;
	}

	ans.writeln;

}
