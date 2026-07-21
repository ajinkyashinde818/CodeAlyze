import std.stdio;
import std.c.stdio;
import std.range;
import std.array;
import std.functional;
import std.algorithm;
import std.conv;
import std.container;
import std.math;
import std.numeric;
import std.string;
import std.c.string;
import std.regex;
import std.typecons;

void main() {
    int M, N, K, D;
    int[] Cal;
    int[][] G;

    int id(string s) {
        if (s == "H") return 0;
        if (s == "D") return M + N + 1;
        if (s[0] == 'C') return 1 + s[1 .. $].to!int - 1;
        if (s[0] == 'L') return 1 + M + s[1 .. $].to!int - 1;
        assert(0);
    }

    int cake_id(int i) {
        return i;
    }
    int landmark_id(int i) {
        return M + i;
    }

    const INF = int.max / 4;
    bool input() {
        scanf("%d %d %d %d\n", &M, &N, &K, &D);
        if (M == 0 && N == 0 && K == 0 && D == 0) return false;
        Cal = readln.chomp.split(" ").map!(to!int).array;
        int Z = M + N + 2;
        G = new int[][](Z, Z);
        foreach (i; 0 .. Z) {
            foreach (j; 0 .. Z) {
                G[i][j] = (i == j ? 0 : INF);
            }
        }
        foreach (i; 0 .. D) {
            string a, b; int d;
            readf("%s %s %d\n", &a, &b, &d);
            int from = id(a),
                to = id(b);
            //[from, to].writeln;
            G[from][to] = min(G[from][to], d * K);
            G[to][from] = min(G[to][from], d * K);
        }
        return true;
    }

    void solve() {
        int Z = M + N + 2;
        foreach (k; 0 .. Z) {
            if (1 <= k && k <= M) continue;
            foreach (i; 0 .. Z) {
                foreach (j; 0 .. Z) {
                    G[i][j] = min(G[i][j], G[i][k] + G[k][j]);
                }
            }
        }

        int calc(int[] path) {
            //writeln(path);
            //write("calc: ", path, " -> ");
            int cur = 0;
            int ret = 0;
            for (int i = 0; i < path.length; i++) {
                int next = path[i] + 1;
                ret += G[cur][next];
                cur = next;
                if (ret >= INF) {
                    //writeln("INF");
                    return INF;
                }
            }
            ret += G[cur][Z - 1];
            if (ret >= INF) {
                //writeln("INF");
                return INF;
            }
            //writeln(ret);
            foreach (i; 0 .. path.length) {
                ret -= Cal[ path[i] ];
            }
            return ret;
        }

        int Ans = INF;
        void permute(int N) {
            auto used = new bool[N];
            int[] res = new int[N];
            void dfs(int i) {
                Ans = min(Ans, calc(res[0 .. i]));
                foreach (j; 0 .. N) {
                    if (used[j]) continue;
                    res[i] = j;
                    used[j] = true;
                    dfs(i + 1);
                    used[j] = false;
                }
            }
            dfs(0);
        }

        permute(M);

        Ans.writeln;

        /*
        foreach (i; 0 .. Z) {
            writefln("%(%3s%)", G[i].map!((a) => (a == INF ? -1 : a)));
        }
        */
    }

    while (input) solve;
}
