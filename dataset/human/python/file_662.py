import std.stdio, std.string, std.conv;
import std.range, std.algorithm, std.array, std.typecons, std.container;
import std.math, std.numeric, core.bitop;

enum inf = 1.0 * 10L^^12;
int n;
real[][] cost;
real[] dist;
real[] x, y, r;

void main() {
    real xs, ys, xt, yt;
    scan(xs, ys, xt, yt);
    int n;

    scan(n);
    x = new real[](n + 2);
    y = new real[](n + 2);
    r = new real[](n + 2);

    x[0] = xs, y[0] = ys, r[0] = 0;
    x[n+1] = xt, y[n+1] = yt, r[n+1] = 0;

    foreach (i ; 1 .. n + 1) {
        scan(x[i], y[i], r[i]);
    }

    cost = new real[][](n + 2, n + 2);
    foreach (i ; 0 .. n + 2) {
        foreach (j ; i .. n + 2) {
            if (i == j) {
                cost[i][i] = 0;
            }
            else {
                cost[i][j] = cost[j][i] = max(0, hypot(x[i] - x[j], y[i] - y[j]) - r[i] - r[j]);
            }
        }
    }

    debug {
        writefln("%(%(%s %)\n%)", cost);
    }

    dist = new real[](n + 2);
    dist[] = inf;
    dist[0] = 0;
    bool[] fix = new bool[](n + 2);

    foreach (_ ; 0 .. n + 2) {
        int v = -1;
        real mx = inf;

        foreach (i ; 0 .. n + 2) {
            if (!fix[i] && mx > dist[i]) {
                v = i;
                mx = dist[i];
            }
        }

        debug {
            writeln("v:", v);
        }

        fix[v] = true;

        foreach (i ; 0 .. n + 2) {
            if (dist[i] > dist[v] + cost[v][i]) {
                dist[i] = dist[v] + cost[v][i];
            }
        }

        debug {
            writeln("dist:", dist);
        }
    }

    debug {
        writeln("dist:", dist);
    }

    writefln("%.12f", dist[n+1]);
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
