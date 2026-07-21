import std.stdio, std.conv, std.string;
import std.array, std.range, std.algorithm, std.container;
import std.math, std.random, std.bigint, std.datetime, std.format;
string read(){ static string[] ss; while(!ss.length) ss = readln.chomp.split; string res = ss[0]; ss.popFront; return res; }

int DEBUG_LEVEL = 0;
void print()(){ writeln(""); }
void print(T, A ...)(T t, lazy A a){ write(t), print(a); }
void print(int level, T, A ...)(T t, lazy A a){ if(level <= DEBUG_LEVEL) print(t, a); }

void main(string[] args){
	if(args.length > 1 && args[1] == "-debug"){
		if(args.length > 2 && args[2].isNumeric) DEBUG_LEVEL = args[2].to!int;
		else DEBUG_LEVEL = 1;
	}
	
	long r = read.to!long;
	long g = read.to!long;
	long b = read.to!long;
	long n = read.to!long;
	
	long ans;
	foreach(i; 0 .. n / r + 1){
		foreach(j; 0 .. n / g + 1){
			long k = (n - (i * r + j * g)) / b;
			if(k < 0) continue;
			if(i * r + j * g + k * b != n) continue;
			print!1("i:", i, " j:", j, " k:", k);
			ans += 1;
		}
	}
	
	ans.writeln;
	
	
}
