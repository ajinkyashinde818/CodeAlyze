import std;

int calc(long k, int[] a) {
    a = [0] ~ a;
    auto used = new long[a.length];
    used[] = -1;
    int p = 1;
    long step = 0;
    while (true) {
        if (step == k) {
            return p;
        }

        if (used[p] != -1) {
            // writeln("loop ", step - used[p]);
            auto m = (k - used[p]) % (step - used[p]);
            // writeln("m ", m);
            m += used[p];

            for (int i = 0; i < a.length; i++) {
                if (used[i] == m) return i;
            }
        }

        used[p] = step++;
        // writeln(p, " -> ", a[p]);
        p = a[p];
    }
    return 0;
}

// ダブリングによる解法
int calc2(long k, int[] a) {
    auto N = a.length;
    const C = 100;

    auto dub = new int[][](C, N);
    // k = 0 のとき(2^k = 0)
    for (int i = 0; i < N; i++)
        dub[0][i] = a[i] - 1;

    // k > 0 のとき
    for (int i = 0; i < C-1; i++) {
        for (int j = 0; j < N; j++) {
            dub[i+1][j] = dub[i][dub[i][j]];
        }
    }

    // k ステップで到達するノード
    auto step = k;
    int now = 0;
    for (int i = 0; ; i++) {
        if (step % 2 == 1) now = dub[i][now];
        step /= 2;
        if (step == 0) break;
    }
    return now + 1;
}

void main() {
    long n, k; scan(n, k);
    auto a = readints;
    writeln(calc2(k, a));
}

void scan(T...)(ref T a) {
    string[] ss = readln.split;
    foreach (i, t; T) a[i] = ss[i].to!t;
}
T read(T=string)() { return readln.chomp.to!T; }
T[] reads(T)() { return readln.split.to!(T[]); }
alias readints = reads!int;
