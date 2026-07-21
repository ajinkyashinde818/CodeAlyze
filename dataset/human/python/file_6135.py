import std.stdio, std.conv, std.string, std.bigint;
import std.math, std.random, std.datetime;
import std.array, std.range, std.algorithm, std.container, std.format;
string read(){ static string[] ss; while(!ss.length) ss = readln.chomp.split; string res = ss[0]; ss.popFront; return res; }

void main(){
	long a = read.to!long;
	long b = read.to!long;
	long c = read.to!long;
	
	long ans;
	if(c > a + b + 1) ans = b + (a + b + 1);
	else ans = b + c;
	
	ans.writeln;
	
	
}
