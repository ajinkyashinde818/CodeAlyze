import std.stdio, std.string, std.conv, std.algorithm;
import std.range, std.array, std.math, std.typecons, std.container, core.bitop;


void main() {
    string s;
    scan(s);
    writeln(s[0 .. $ - 8]);
}



void scan(T...)(ref T args) {
    string[] line = readln.split;
    foreach (ref arg; args) {
        arg = line.front.to!(typeof(arg));
        line.popFront();
    }
    assert(line.empty);
}



void fillAll(R, T)(ref R arr, T value) {
    static if (is(typeof(arr[] = value))) {
        arr[] = value;
    }
    else {
        foreach (ref e; arr) {
            fillAll(e, value);
        }
    }
}
