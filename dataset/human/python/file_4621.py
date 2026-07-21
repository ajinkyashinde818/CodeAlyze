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

char decode(char c, int n) {
	while(n > 0) {
		switch(c) {
			case 'a':
				c = 'Z';
				break;
			case 'A':
				c = 'z';
				break;
			default:
				--c;
		}
		--n;
	}
	return c;
}

void main(){
	while(true) {
		auto n = readInt;
		if(n == 0) return;
		auto k = readInts;
		auto s = readln.chomp;
		foreach(i, c; s) {
			write(decode(c, k[i%n]));
		}
		writeln();
	}
}
