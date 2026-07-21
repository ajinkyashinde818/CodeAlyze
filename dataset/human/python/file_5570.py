import std.stdio, std.string, std.conv, std.algorithm;
import std.range, std.array, std.math, std.typecons, std.container, core.bitop;


void main() {
    auto s = readln.chomp.to!(char[]);

    long ans;

    while (!s.empty) {
        if (s.length == 1) break;
        if (s.front == s.back) {
            s.popFront();
            s.popBack();
        }
        else if (s.front == 'x') {
            ans++;
            s.popFront();
        }
        else if (s.back == 'x') {
            ans++;
            s.popBack();
        }
        else {
            writeln(-1);
            return;
        }
    }

    writeln(ans);
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
