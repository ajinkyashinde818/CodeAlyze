import std.stdio, std.math, std.algorithm, std.array, std.string, std.conv, std.container, std.range;
pragma(inline, true) T[] Reads(T)() { return readln.split.to!(T[]); }
alias reads = Reads!int;
pragma(inline, true) void scan(Args...)(ref Args args) {
    string[] ss = readln.split;
    foreach (i, ref arg ; args) arg = ss[i].parse!int;
}

void main() {
    int n; scan(n);
    int[] a = reads().map!(i => i-1).array;
    int[] b = reads();
    int[] c = reads();

    int pre = -100, ans=0;
    foreach (x; a) {
        ans += b[x];
        if (x == pre + 1) ans += c[pre];
        pre = x;
    }
    writeln(ans);
}
