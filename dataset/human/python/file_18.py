import std.stdio, std.array, std.conv, std.typecons, std.algorithm;

T diff(T)(const ref T a, const ref T b) { return a > b ? a - b : b - a; }

void main() {
    immutable i = readln.split.to!(ulong[]);
    immutable R = i[0], G = i[1], B = i[2], N = i[3];
    ulong cnt = 0;

    for(ulong r = 0; r <= N / R; r++) {
        const ulong r_val = r * R;
        if (r_val > N) break;
        else if (r_val == N) cnt++;
        else {
            for(ulong g = 0; g <= N / G; g++) {
                const ulong g_val = r*R + g*G;
                if (g_val > N) break;
                else if (g_val == N) cnt++;
                else {
                    const ulong rem = (N - g_val) % B;
                    if (rem == 0) {
                        cnt++;
                    }
                }
            }
        }
    }
    writeln(cnt);
}
