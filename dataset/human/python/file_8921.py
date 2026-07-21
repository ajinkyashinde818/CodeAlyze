import std.stdio, std.string, std.conv, std.range;
import std.algorithm, std.array, std.typecons, std.container;
import std.math, std.numeric, std.random, core.bitop;

void scan(T...)(ref T args) {
    auto line = readln.split;
    foreach (ref arg; args) {
        arg = line.front.to!(typeof(arg));
        line.popFront;
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

bool chmin(T, U...)(ref T x, U args) {
    bool isChanged;
    foreach (arg; args) if (x > arg) {
        x = arg;
        isChanged = true;
    }
    return isChanged;
}

bool chmax(T, U...)(ref T x, U args) {
    bool isChanged;
    foreach (arg; args) if (x < arg) {
        x = arg;
        isChanged = true;
    }
    return isChanged;
}


enum mod = 1_000_000_007L;

struct Mint {
    long x;

    this(long a) {
        x = a % mod;
        if (x < 0) x += mod;
    }

    this(Mint a) {
        x = a.x;
    }

    ref Mint opAssign(long a) {
        this = Mint(a);
        return this;
    }

    ref Mint opOpAssign(string op)(Mint rhs) {
        static if (op == "+") {
            x += rhs.x;
            if (x >= mod) x -= mod;
        }
        static if (op == "-") {
            x -= rhs.x;
            if (x < 0) x += mod;
        }
        static if (op == "*") {
            (x *= rhs.x) %= mod;
        }
        static if (op == "/") {
            this *= rhs.inv();
        }
        return this;
    }

    ref Mint opOpAssign(string op)(long rhs) {
        static if (op == "^^") {
            this = powmod(this, rhs);
            return this;
        }
        else {
            return mixin("this " ~ op ~ "= Mint(rhs)");
        }
    }

    const Mint powmod(Mint a, long b) {
        Mint res = 1, p = a;
        while (b > 0) {
            if (b & 1) res *= p;
            p *= p;
            b /= 2;
        }
        return res;
    }

    const Mint inv() {
        return powmod(this, mod - 2);
    }

    Mint opUnary(string op)() if (s == "-") {
        return Mint(-x);
    }

    Mint opBinary(string op, T)(const T rhs) {
        return mixin("Mint(this) " ~ op ~ "= rhs");
    }

    Mint opBinaryRight(string op)(const long rhs) {
        return mixin("Mint(rhs) " ~ op ~ "= this");
    }

    bool opEquals(Mint a, Mint b) {
        return a.x == b.x;
    }

    bool opEquals(long rhs) {
        long y = rhs % mod;
        if (y < 0) y += mod;
        return x == y;
    }

    string toString() {
        import std.conv : to;
        return x.to!string;
    }
}

unittest {
    long powmod(long a, long b) {
        return b > 0 ? powmod(a, b / 2)^^2 % mod * a^^(b & 1) % mod : 1L;
    }
    auto a = Mint(2), b = Mint(3);
    assert(a + b == 5);
    assert(a + 5 == 7);
    assert(1 + b == 4);
    assert(a - b == mod - 1);
    assert(a * b == 6);
    assert(a / b == 2 * powmod(3, mod - 2));
    assert(a^^10 == 1024);

    Mint z;
    assert(z == 0);

    (z += 2) *= 3;
    assert(z == 6);
}



enum inf = 1_001_001_001;
enum infl = 1_001_001_001_001_001_001L;


void main() {
    string s;
    scan(s);

    auto p = ["dream", "dreamer", "erase", "eraser"];

    while (!s.empty) {
        bool e;
        foreach (str ; p) {
            if (str.length > s.length) continue;
            if (str == s[$ - str.length .. $]) {
                s = s[0 .. $ - str.length];
                e = true;
                break;
            }
        }
        if (!e) {
            writeln("NO");
            return;
        }
    }
    writeln("YES");
}
