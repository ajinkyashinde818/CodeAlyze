import std.algorithm;
import std.array;
import std.ascii;
import std.container;
import std.conv;
import std.math;
import std.numeric;
import std.range;
import std.stdio;
import std.string;
import std.typecons;
void log(A...)(A arg) { stderr.writeln(arg); }
int size(T)(in T s) { return cast(int)s.length; }

void main() {
    int N, M; readf("%d %d\n", &N, &M);
    auto A = new string[N];
    auto B = new string[M];
    foreach (i; 0 .. N) { A[i] = readln.chomp; }
    foreach (i; 0 .. M) { B[i] = readln.chomp; }

    bool check(int sy, int sx) {
        int ty = sy + M;
        int tx = sx + M;
        for (int y = sy; y < ty; y++) {
            for (int x = sx; x < tx; x++) {
                if (A[y][x] != B[y - sy][x - sx]) return false;
            }
        }
        return true;
    }

    int ans = 0;
    for (int sy = 0; sy <= N - M; sy++) {
        for (int sx = 0; sx <= N - M; sx++) {
            if (check(sy, sx)) ans++;
        }
    }
    writeln(ans > 0 ? "Yes" : "No");
}
