import std.stdio, std.conv, std.string, std.array, std.range, std.algorithm, std.container;
import std.math, std.random, std.bigint, std.datetime, std.format;
void main(string[] args){ if(args.length > 1) if(args[1] == "-debug") DEBUG = 1; solve(); }
void log()(){ writeln(""); } void log(T, A ...)(T t, lazy A a){ if(DEBUG) write(t, " "), log(a); } bool DEBUG = 0; 
string read(){ static string[] ss; while(!ss.length) ss = readln.chomp.split; string res = ss[0]; ss.popFront; return res; }
// ----- ----- ----- ----- ----- ----- ----- ----- ----- ----- ----- ----- //

void solve(){
	int n = read.to!int;
	string s = readln.chomp;
	
	bool[] isLeft = new bool[](n * 2);
	bool isOdd = 0;
	foreach(i, c; s){
		if(isOdd && c == 'W'){
			isLeft[i] = 1;
			isOdd = 0;
		}
		else if(isOdd && c == 'B'){
			isLeft[i] = 0;
			isOdd = 0;
		}
		else if(! isOdd && c == 'W'){
			isLeft[i] = 0;
			isOdd = 1;
		}
		else if(! isOdd && c == 'B'){
			isLeft[i] = 1;
			isOdd = 1;
		}
	}
	log("isLeft", isLeft.map!(x => x ? '+': '-'));
	
	Finite ans = Finite(1);
	long leftc = 0;
	foreach(i, isL; isLeft){
		if(isL){
			leftc += 1;
		}
		else{
			if(leftc == 0){
				ans = Finite(0);
				break;
			}
			else{
				ans *= leftc;
				leftc -= 1;
			}
		}
		log("i:", i, "ans:", ans);
	}
	if(leftc > 0) ans = Finite(0);
	
	foreach(i; 1 .. n + 1) ans *= i;
	
	ans.writeln;
}


import std.conv;
struct Finite{ ulong value; static ulong mod = 1_000_000_007;
	private static ulong[] _inv = [0, 1], _frac = [1, 1], _invfrac = [1, 1];
	this(ulong v){ value = v % mod; }
	bool opCast(T: bool)(){ return value != 0; }
	Finite opUnary(string s){ ulong v;
		if(s == "+") v = value;
		else if(s == "-") v = mod - value;
		else if(s == "++") v = value + 1;
		else if(s == "--") v = value + mod - 1;
		else assert(0, "Operator unary " ~ s ~ " not implemented");
		return Finite(v);
	}
	Finite opBinary(string s)(Finite b){
		return opBinary!s(b.value);
	}
	Finite opBinary(string s)(ulong u){ ulong v;
		if(s == "+") v = value + u;
		else if(s == "-") v = value + mod - u;
		else if(s == "*") v = value * u;
		else if(s == "/") v = value * inv(u);
		else assert(0, "Operator " ~ s ~ " not implemented");
		return Finite(v);
	}
	Finite opBinaryRight(string s)(ulong u){ ulong v;
		if(s == "+") v = u + value;
		else if(s == "-") v = u + mod - value;
		else if(s == "*") v = u * value;
		else if(s == "/") v = u * invvalue;
		else assert(0, "Operator " ~ s ~ " not implemented");
		return Finite(v);
	}
	Finite opAssign(ulong v){ value = v; return this; }
	Finite opOpAssign(string s)(Finite b){
		return opOpAssign!s(b.value);
	}
	Finite opOpAssign(string s)(ulong v){
		if(s == "+") value = (value + v) % mod;
		else if(s == "-") value = (value + mod - v) % mod;
		else if(s == "*") value = (value * v) % mod;
		else if(s == "/") value = (value * inv(v)) % mod;
		else assert(0, "Operator " ~ s ~ "= not implemented");
		return this;
	}
	bool opEquals(Finite b){
		return(value == b.value);
	}
	string toString(){ return value.to!string; }
	ulong inv(ulong v){
		assert(v > 0);
		assert(v < mod);
		while(v >= _inv.length){
			_inv ~= _inv[mod % $] * (mod - mod / _inv.length) % mod;
		}
		return _inv[v.to!uint];
	}
	ulong invvalue(){
		return inv(value);
	}
	static Finite opCall(ulong v){
		return Finite(v);
	}
}
