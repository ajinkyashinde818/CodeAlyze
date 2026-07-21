import std.stdio, std.string, std.conv;
import std.typecons;
import std.algorithm, std.array, std.range, std.container;
import std.math;

void main() {
	auto data = readln.split.to!(int[]);
	auto A = data[0], B = data[1], C = data[2];
	if (A+B >= C-1) writeln(B+C);
	else writeln( B + A+B+1 );
}
