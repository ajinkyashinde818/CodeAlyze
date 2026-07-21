import std.stdio;
import std.string;
import std.conv;
import std.algorithm;
import std.math;
import std.range;

void main(){
	auto N = readln.chomp.to!int;
	if(N/10==9 || N%10==9) writeln("Yes");
	else writeln ("No");
	

}
