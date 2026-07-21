import std.stdio, std.string, std.conv;
import std.range, std.algorithm, std.array;


void main() {
    char x, y;
    scan(x, y);

    if (x < y) {
        writeln("<");
    }
    else if (x > y) {
        writeln(">");
    }
    else {
        writeln("=");
    }
}



void scan(T...)(ref T args) {
    import std.stdio : readln;
    import std.algorithm : splitter;
    import std.conv : to;
    import std.range.primitives;

    auto line = readln().splitter();
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
