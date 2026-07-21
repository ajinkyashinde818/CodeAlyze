import std.stdio, std.string, std.conv, std.range, std.algorithm;

void main() {
    auto S = readln.split.to!(int[]);
    auto N = S[0], M = S[1];
    auto A = new bool[][N];
    auto B = new bool[][M];
    foreach (i; 0..N) {
        A[i] = readln.chomp.map!(a => a == '#').array;
    }
    foreach (i; 0..M) {
        B[i] = readln.chomp.map!(a => a == '#').array;
    }
    foreach (i; 0..N-M+1) {
        foreach (j; 0..N-M+1) {
            bool flag = true;
            foreach(x; 0..M) {
                foreach (y; 0..M) {
                    if (A[x+i][y+j] != B[x][y]) {
                        flag = false;
                        break;
                    }
                }
                if (!flag) break;
            }
            if (flag) {
                writeln("Yes");
                return;
            }
        }
    }
    writeln("No");
}
