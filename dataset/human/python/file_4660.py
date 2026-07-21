import std.stdio, std.string, std.conv, std.algorithm, std.numeric;
import std.range, std.array, std.math, std.typecons, std.container, core.bitop;
import std.ascii;

void main() {
    int n;
    scan(n);

    foreach (i ; 0 .. n) {
        string s1,s2;
        scan(s1, s2);
        writeln(i2m(m2i(s1) + m2i(s2)));
    }
}

int m2i(string s) {
    int res;
    int[char] t = ['m':1000, 'c':100, 'x':10, 'i':1];

    while (!s.empty) {
        if (s[0].isDigit) {
            res += (s[0] - '0') * t[s[1]];
            s.popFrontN(2);
        }
        else {
            res += t[s[0]];
            s.popFront;
        }
    }

    return res;
}

string i2m(int x) {
    char[] res;
    char[int] t = [3:'m', 2:'c', 1:'x', 0:'i'];

    int d;

    while (x > 0) {
        int r = x % 10;

        if (r > 0) {
            res ~= t[d];
        }
        if (r > 1) {
            res ~= r + '0';
        }

        x /= 10;
        d++;
    }

    res.reverse();

    return res.to!string;
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
