import std.stdio;
import std.string;
import std.conv;
import std.algorithm;
import std.range;
import std.array;

void main(){
	auto s=readln.chomp;
	if(s=="abc"||s=="acb"||s=="bac"||s=="bca"||s=="cab"||s=="cba")writeln("Yes");
	else writeln("No");
}
