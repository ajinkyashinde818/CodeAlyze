import std.stdio;
import std.string;
import std.conv;
import std.algorithm.searching;

void main(){
	auto str = readln.chomp;
	if(str.canFind("a") && str.canFind("b") && str.canFind("c")){
		"Yes".writeln;
	}else{
		"No".writeln;
	}
}
