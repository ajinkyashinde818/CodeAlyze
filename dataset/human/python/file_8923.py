void main(){
	string s = readln().chomp().dup().reverse();
	string[] chk = ["remaerd", "maerd", "resare", "esare"];
	bool is_continue = true;
	while(is_continue){
		foreach(i,elm; chk){
			if(s.indexOf(elm)==0){
				s = s[elm.length..$];
				break;
			}
			// 最後まで見つからなければ終わり
			else if(i==3)is_continue = false;
		}
	}
	writefln("%s", s.length==0? "YES":"NO");
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
