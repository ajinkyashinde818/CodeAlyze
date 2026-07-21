import std.stdio;
import std.string;
import std.range;
import std.algorithm;

void main() {
	auto s = readln.chomp.retro.array;
	auto cands = ["dream", "dreamer", "erase", "eraser"].map!(s => s.retro.array).array;
	int idx = 0;
	while(true) {
		bool succ;
		if (idx >= s.length-1) break;
		foreach(cand; cands) {
			if (idx+cand.length <= s.length && s[idx..idx+cand.length] == cand) {
				idx += cand.length;
				succ = true;
				break;
			}
		}
		if (!succ) {
			"NO".write;
			return;
		}
	}
	"YES".write;
}
