void main(){
	string n = readln().chomp();
	writeln(n.count('9')==0? "No": "Yes");
}

import std.stdio, std.conv, std.algorithm, std.numeric, std.string, std.math;

// 1要素のみの入力
T _scan(T= int)(){
	return to!(T)( readln().chomp() );
}

// 1行に同一型の複数入力
T[] _scanln(T = int)(){
	T[] ln;
	foreach(string elm; readln().chomp().split()){
		ln ~= elm.to!T();
	}
	return ln;
}
