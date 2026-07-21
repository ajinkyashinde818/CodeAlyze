import std.stdio, std.string, std.conv;
import std.range, std.algorithm, std.array;


void main() {
    int N;
    long L;
    scan(N, L);

    auto s = new string[](N);
    iota(N).each!(i => s[i] = readln.chomp);

    auto ssum = s.map!(si => si.length.to!int).sum();

    auto nex = new int[][](ssum * 2, 2);
    fillAll(nex, -1);
    int m = 1;

    foreach (i ; 0 .. N) {
        int k = s[i].length.to!int;
        int v = 0;
        foreach (j ; 0 .. k) {
            int c = s[i][j] - '0';
            if (nex[v][c] == -1) {
                nex[v][c] = m++;
            }
            v = nex[v][c];
        }
    }

    debug {
        writeln(nex);
    }

    int nim;

    void dfs(int v, int dep) {
        if (nex[v][0] == -1 && nex[v][1] == -1) {
            return;
        }
        else if (nex[v][0] == -1 || nex[v][1] == -1) {
            long h = L - dep;
            int m = 1;

            while (!(h & 1)) {
                h >>= 1;
                m++;
            }

            nim ^= m;

            if (nex[v][0] == -1) {
                dfs(nex[v][1], dep + 1);
            }
            else {
                dfs(nex[v][0], dep + 1);
            }
        }
        else {
            dfs(nex[v][0], dep + 1);
            dfs(nex[v][1], dep + 1);
        }
    }

    dfs(0, 0);

    writeln(nim ? "Alice" : "Bob");
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
