import std.stdio;
import std.conv;
import std.array;
import std.string;
import std.algorithm;

void main() {
	string S;
	S = chomp(readln());
	string res = "";
	if(S[0] == '9' || S[1] == '9') {
		res = "Yes";
	}
	else{
		res = "No";
	}
	writeln(res);
}
