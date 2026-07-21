import std.stdio, std.string, std.conv;
import std.range, std.algorithm, std.array, std.typecons, std.container;
import std.math, std.numeric, core.bitop;

enum inf3 = 1_001_001_001;
enum inf6 = 1_001_001_001_001_001_001L;
enum mod = 1_000_000_007L;


void main() {
    int n; string s;
    scan(n);
    scan(s);
    auto cnt = new int[](26);
    foreach (ch ; s) {
        cnt[ch - 'a']++;
    }
    long ans = 1;
    foreach (i ; 0 .. 26) {
        ans *= cnt[i] + 1;
        ans %= mod;
    }
    ans += mod - 1;
    ans %= mod;
    writeln(ans);
}



























int[][] readGraph(int n, int m, bool isUndirected = true, bool is1indexed = true) {
    auto adj = new int[][](n, 0);

    foreach (i; 0 .. m) {
        int u, v;
        scan(u, v);
        if (is1indexed) {
            u--, v--;
        }
        adj[u] ~= v;
        if (isUndirected) {
            adj[v] ~= u;
        }
    }

    return adj;
}

alias Edge = Tuple!(int, "to", int, "cost");

Edge[][] readWeightedGraph(int n, int m, bool isUndirected = true, bool is1indexed = true) {
    auto adj = new Edge[][](n, 0);

    foreach (i; 0 .. m) {
        int u, v, c;
        scan(u, v, c);
        if (is1indexed) {
            u--, v--;
        }
        adj[u] ~= Edge(v, c);
        if (isUndirected) {
            adj[v] ~= Edge(u, c);
        }
    }

    return adj;
}

void yes(bool b) {
    writeln(b ? "Yes" : "No");
}

void YES(bool b) {
    writeln(b ? "YES" : "NO");
}

T[] readArr(T)() {
    return readln.split.to!(T[]);
}

T[] readArrByLines(T)(int n) {
    return iota(n).map!(i => readln.chomp.to!T).array;
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

bool chmin(T, U...)(ref T x, U args) {
    bool isChanged;

    foreach (arg; args) {
        if (x > arg) {
            x = arg;
            isChanged = true;
        }
    }

    return isChanged;
}

bool chmax(T, U...)(ref T x, U args) {
    bool isChanged;

    foreach (arg; args) {
        if (x < arg) {
            x = arg;
            isChanged = true;
        }
    }

    return isChanged;
}
