import std.stdio;
import std.string;
import std.conv;
import std.algorithm;
import std.array;

void main() {
	auto first = new char[0];
	auto last = readln.chomp.dup;

	uint queryMax = readln.chomp.to!uint;

	foreach (i;0..queryMax) {
		auto query = readln.chomp.split(' ');

		if (query[0] == "1") {
			swap(first, last);
		} else if (query[0] == "2") {
			if (query[1] == "1") {
				first ~= query[2];
			} else if (query[1] == "2") {
				last ~= query[2];
			} else {
				assert(false);
			}
		} else {
			assert(false);
		}
	}

	foreach_reverse (c;first) {
		write(c);
	}
	writeln(last);
}
