import std.stdio, std.algorithm, std.conv, std.array, std.string, std.math, std.typecons, std.numeric, std.container, std.range;

void main()
{
    auto N = readln.chomp.to!int;
    auto AS = readln.split.to!(int[]);
    auto BS = readln.split.to!(int[]);

    auto ns = new int[](N+1);
    auto cs = new int[][N+1];
    int d;
    int[] dis;
    foreach (i; 0..N) {
        auto a = AS[i];
        auto b = BS[i];
        ++ns[a];
        ++ns[b];
        if (a == b) {
            ++d;
            dis ~= i;
            cs[a] ~= i;
        }
    }
    foreach (i; 0..N) if (ns[i+1] > N) {
        writeln("No");
        return;
    }

    int max_cl, max_ci;
    foreach (i, c; cs) {
        auto cl = c.length.to!int;
        if (cl > max_cl) {
            max_cl = cl;
            max_ci = i.to!int;
        }
    }

    if (max_cl == d) {
        auto X = max_ci;
        int i;
        foreach (di; dis) {
            while (AS[i] == X || BS[i] == X) ++i;
            swap(BS[di], BS[i++]);
        }
        writeln("Yes");
        writeln(BS.to!(string[]).join(" "));
        return;
    } else if (max_cl > d/2) {
        bool[int] dim;
        foreach (di; dis) dim[di] = true;
        auto X = max_ci;
        int i, j;
        while (max_cl > d/2) {
            while (AS[i] == X || BS[i] == X) ++i;
            dim[cs[X][j]] = false;
            if (i in dim) {
                dim[i] = false;
                --d;
            }
            swap(BS[i++], BS[cs[X][j++]]);
            --max_cl;
            --d;
        }
        int[] ndis;
        foreach (k, v; dim) if (v) ndis ~= k;
        sort(ndis);
        dis = ndis;
    }

    auto ii = 0.iota(N).array;
    foreach (i, di; dis) {
        ii[di] = dis[(i+d/2)%d];
    }
    writeln("Yes");
    writeln(ii.map!(i => BS[i]).array.to!(string[]).join(" "));
}
