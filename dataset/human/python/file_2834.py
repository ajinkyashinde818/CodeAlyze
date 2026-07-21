import std;

long calc(long n) {
    if (n == 1) return 0;

    int ans = 0;
    foreach (p; factor(n)) {

        long k = p[1];
        for (int i = 1; ; i++) {
            if (k >= i) {
                k -= i;
                ans++;
            } else break;
        }
    }
    return ans;
}

void main() {
    long n; scan(n);
    writeln(calc(n));
}

void scan(T...)(ref T a) {
    string[] ss = readln.split;
    foreach (i, t; T) a[i] = ss[i].to!t;
}
T read(T=string)() { return readln.chomp.to!T; }
T[] reads(T)() { return readln.split.to!(T[]); }
alias readints = reads!int;

// 素因数分解([[素因数, 個数], ...])
T[][] factor(T)(T n) {
    if (n == 1) return [[1, 1]];
    long[][] res;
    for (T i = 2; i * i <= n; i++) {
        if (n % i != 0) continue;
        int k = 0;
        while (n % i == 0) { n /= i; k++; }
        res ~= [i, k];
    }
    if (n > 1) res ~= [n, 1];
    return res;
}
