import std.stdio, std.string, std.conv, std.range;
import std.algorithm, std.array, std.typecons, std.container;
import std.math, std.numeric, std.random, core.bitop;

enum inf = 1_001_001_001;
enum infl = 1_001_001_001_001_001_001L;


void main() {
    int N;
    scan(N);
    auto a = readln.split.to!(int[]);
    auto b = readln.split.to!(int[]);

    foreach (i ; 0 .. N) {
        if (a[i] != b[i] && b[i] >= (a[i] + 1) / 2) {
            writeln(-1);
            return;
        }
    }

    // dp(x, y, i) = 1 ~ i を使って x を y にできるか
    auto dp = new bool[][][](51, 51, 51);
    foreach (i ; 0 .. 51) {
        dp[i][i][0] = true;
    }

    foreach (i ; 1 .. 51) {
        foreach (x ; 0 .. 51) {
            foreach (y ; 0 .. 51) {
                dp[x][y][i] = dp[x][y][i - 1] || dp[x % i][y][i - 1];
            }
        }
    }
    

    auto s = new long[](N);
    foreach (i ; 0 .. N) {
        s[i] = 1L << a[i];
    }

    long ans;

    foreach_reverse (k ; 1 .. 51) {
        bool use;

        foreach (i ; 0 .. N) {
            bool ok;
            foreach (j ; 0 .. 51) if (s[i] & 1L << j) {
                ok |= dp[j][b[i]][k - 1];
            }
            if (!ok) {
                use = true;
                break;
            }
        }

        if (!use) continue;

        ans += 1L << k;
        foreach (i ; 0 .. N) {
            foreach (j ; 0 .. 51) if (s[i] & 1L << j) {
                s[i] |= 1L << (j % k);
            }
        }
    }

    debug {
        writefln("%b", ans);
    }
    writeln(ans);
}






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

void yes(bool ok, string y = "Yes", string n = "No") {
    return writeln(ok ? y : n);
}
