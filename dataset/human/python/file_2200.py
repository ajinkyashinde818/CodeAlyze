import std.algorithm;
import std.array;
import std.conv;
import std.math;
import std.range;
import std.stdio;
import std.string;
import std.typecons;

T read(T)() { return readln.chomp.to!T; }
T[] reads(T)() { return readln.split.to!(T[]); }
alias readint = read!int;
alias readints = reads!int;

int calc(int g, int[][] ps) {
    int n = cast(int)ps.length;

    int ans = int.max;
    for (int i = 0; i < (1 << n); i++) {
        int score = 0;
        int solved = 0; // 解いた問題数
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) { // j は全て解く
                score += 100 * (j+1) * ps[j][0] + ps[j][1];
                solved += ps[j][0];
            }
        }

        if (score >= g) {
            ans = min(ans, solved);
        }
        else {
            // score が足りないなら、まだ解いていない問題から点数の高い問題を解く
            for (int j = n-1; j >= 0; j--) {
                if (i & (1 << j)) continue;

                int s = 100 * (j+1) * ps[j][0]; // 得られるスコア
                int x = g - score; // 不足分のスコア
                if (x <= s) {
                    int r = x / (100 * (j+1));
                    int m = x % (100 * (j+1));

                    solved += r + (m > 0 ? 1 : 0);
                    ans = min(ans, solved);
                }
                break;
            }
        }
    }

    return ans;
}

void main() {
    auto dg = readints;
    int d = dg[0], g = dg[1];

    int[][] ps;
    for (int i = 0; i < d; i++) {
        ps ~= readints;
    }
    writeln(calc(g, ps));
}
