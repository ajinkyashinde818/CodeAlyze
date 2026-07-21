import std.stdio, std.string, std.conv;
import std.range, std.algorithm, std.array;


void main() {
    dchar[] s;
    scan(s);
    s.sort();

    if (s == "abc") {
        writeln("Yes");
    }
    else {
        writeln("No");
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
