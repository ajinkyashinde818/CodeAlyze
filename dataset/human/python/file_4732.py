import std.stdio : writeln;

void main() {
    import std.algorithm : sort;
    
    dchar[] s,t;
    scan(s);
    scan(t);

    s.sort();
    t.sort!"a > b"();

    writeln(s < t ? "Yes" : "No");
}




void scan(T...)(ref T args) {
    import std.stdio : readln;
    import std.array : split;
    import std.conv  : to;
    import std.range.primitives;

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
