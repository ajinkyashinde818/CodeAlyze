import std.stdio;
import std.algorithm;
import std.string;
import std.range;
import std.array;
import std.conv;
import std.complex;
import std.math;
import std.ascii;
import std.bigint;
import std.container;
import std.typecons;

auto readInts() {
	return array(map!(to!int)(readln().strip().split()));
}
auto readInt() {
	return readInts()[0];
}
auto readLongs() {
	return array(map!(to!long)(readln().strip().split()));
}
auto readLong() {
	return readLongs()[0];
}

const real eps = 1e-10;

string dec2mcxi(int d) {
	string ret;
	int m = d/1000;
	int c = (d%1000)/100;
	int x = (d%100)/10;
	int i = d%10;
	if(m > 1) {
		ret = ret ~ to!string(m);
	}
	if(m > 0) {
		ret = ret ~ "m";
	}
	if(c > 1) {
		ret = ret ~ to!string(c);
	}
	if(c > 0) { 
		ret = ret ~ "c";
	}
	if(x > 1) {
		ret = ret ~ to!string(x);
	}
	if(x > 0) { 
		ret = ret ~ "x";
	}
	if(i > 1) {
		ret = ret ~ to!string(i);
	}
	if(i > 0) { 
		ret = ret ~ "i";
	}
	return ret;
}

int mcxi2dec(string s) {
	int ret;
	while(!s.empty) {
		int tmp = 1;
		if('2' <= s[0] && s[0] <= '9') {
			tmp = s[0] - '0';
			s = s[1..$];
		}
		switch(s[0]) {
			case 'm':
				ret += tmp * 1000;
				break;
			case 'c':
				ret += tmp * 100;
				break;
			case 'x':
				ret += tmp * 10;
				break;
			case 'i':
				ret += tmp;
				break;
			default:
				break;
		}
		s = s[1..$];
	}
	return ret;
}

void main(){
	auto n = readInt();
	for(int i; i < n; ++i) {
		auto s = readln.strip.split;
		writeln(dec2mcxi(mcxi2dec(s[0]) + mcxi2dec(s[1])));
	}
}
