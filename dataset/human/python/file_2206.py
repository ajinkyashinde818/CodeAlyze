import std.stdio, std.string, std.range, std.conv, std.array, std.algorithm, std.math, std.typecons;

void main() {
    auto tmp = readln.split.to!(long[]);
    const D = tmp[0], G = tmp[1];
    struct Po { long p, c; }
    auto po = new Po[D];
    auto completePointList = new long[D];
    foreach (i; 0..D) {
        tmp = readln.split.to!(long[]);
        const p = tmp[0], c = tmp[1];
        po[i] = Po(p,c);
        completePointList[i] = 100 * (i+1) * p + c;
    }

    long calc(bool[] s) {
        long problem = 0;
        long point = 0;
        foreach (i, b; s) {
            if (!b) continue;
            point += 100 * (i+1) * po[i].p + po[i].c;
            problem += po[i].p;
        }
        foreach_reverse (i; 0..D) {
            if (s[i]) continue;
            if (point >= G) return problem;
            const cnt = cast(long)min(po[i].p-1, ceil((G - point) / (100.0 * (i+1))));
            problem += cnt;
            point += 100 * (i+1) * cnt;
        }
        return point < G ? 114514 : problem;
    }

    long func(long i, bool[] s) {
        if (i == D) {
            return calc(s);
        }
        return min(func(i+1, s.dup ~ false), func(i+1, s.dup ~ true));
    }
    writeln(func(0,[]));
}
