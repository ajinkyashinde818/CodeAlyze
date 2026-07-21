import std.stdio, std.conv, std.string, std.array, std.range, std.algorithm, std.container;
import std.math, std.random, std.bigint, std.datetime, std.format;
void main(string[] args){ if(args.length > 1) if(args[1] == "-debug") DEBUG = 1; solve(); }
void log()(){ writeln(""); } void log(T, A ...)(T t, lazy A a){ if(DEBUG) write(t, " "), log(a); } bool DEBUG = 0; 
string read(){ static string[] ss; while(!ss.length) ss = readln.chomp.split; string res = ss[0]; ss.popFront; return res; }
T rtype(T)(){ return read.to!T; } alias rint = rtype!int, rlong = rtype!long, rreal = rtype!real;
T[] rtypes(T)(int n){ return n.iota.map!(i => rtype!T()).array; } alias rint = rtypes!int, rlong = rtypes!long, rreal = rtype!real;

// ----- ----- ----- ----- ----- ----- ----- ----- ----- ----- ----- ----- //

void solve(){
	int d = rint;
	long g  = rlong;
	
	X[] xs;
	foreach(k; 0 .. d) xs ~= X((k + 1) * 100, rint, rlong);
	log("xs:", xs);
	
	long best = 1_000_000_999;
	foreach(m; 0 .. 1L<<d){
		long sum;
		long cnt;
		foreach(i, x; xs) if((1L<<i) & m){
			sum += x.p * x.v + x.c;
			cnt += x.p;
		}
		log("m:", m, "sum:", sum, "cnt:", cnt);
		if(sum >= g) best = min(best, cnt);
		else{
			X xmax;
			foreach(i, x; xs) if(!((1L<<i) & m)){
				xmax = x;
			}
			if(sum + (xmax.p - 1) * xmax.v >= g){
				while(sum < g){
					sum += xmax.v;
					cnt += 1;
				}
				if(sum >= g) best = min(best, cnt);
			}
			log("m:", m, "xmax.v:", xmax.v);
		}
		log("m:", m,  "sum:", sum, "cnt:", cnt, "best:", best);
	}
	best.writeln;
	
}

struct X{
	int v;
	int p;
	long c;
}
