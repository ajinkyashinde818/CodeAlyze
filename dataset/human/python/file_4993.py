import std.stdio, std.string, std.conv;
import std.array, std.algorithm, std.range;

void main()
{
    foreach(s;stdin.byLine())
    {
        immutable N = 8;
        auto c = s.split().map!(to!int).array();
        auto a = [4,1,4,1,2,1,2,1].cycle().take(N*2).array();
        int v=int.min;
        int p;
        int n;
        foreach(i;0..N)
        {
            auto b = a[i..i+N];
            auto u = zip(c,b).map!(t=>min(t[0],t[1])).reduce!"a+b"();
            if(v<=u)
            {
                auto m = b.map!(to!string).join().to!int();
                if(v<u || n>m)
                    v=u,p=i,n=m;
            }
        }
        a[p..p+N].map!(to!string).join(" ").writeln();
    }
}
