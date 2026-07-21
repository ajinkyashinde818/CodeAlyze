import std.stdio, std.range, std.algorithm, std.conv, std.string, std.array, std.typecons, std.format;

void main() {
    long r,g,b,n;
    readf("%d %d %d %d", &r, &g, &b, &n);

    long ans = 0;
    for (long i = 0; r*i <= n; i++) {
    for (long j = 0; r*i + b*j <= n; j++) {
        if ((n - (r*i + b*j)) % g == 0)  {
            ans++;
        }
    }
    }
    writeln(ans);

}
