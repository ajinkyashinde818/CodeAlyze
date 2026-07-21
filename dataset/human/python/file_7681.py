import std.stdio, std.string, std.conv;
import std.array, std.algorithm, std.range;

auto solve(immutable int n)
{
    auto a = iota(n).map!(_=>readln().chomp()).array();
    auto dp = new int[][](n+1,n+1);
    foreach(i;0..n)
        foreach(j;0..n)
            dp[i+1][j+1]=dp[i][j+1]+dp[i+1][j]-dp[i][j]+(a[i][j]!='.'?1:0);
    int m = 0;
    foreach(i;0..n)
        foreach(j;0..n)
        {
            int lo=0, hi=min(n-i,n-j)+1;
            while(lo+1<hi)
            {
                immutable k = (lo+hi)/2;
                if(0==dp[i+k][j+k]-dp[i][j+k]-dp[i+k][j]+dp[i][j])
                    lo=k;
                else
                    hi=k;
            }
            m=max(m,lo);
        }
    return m;
}

void main()
{
    for(int n; 0!=(n=readln().chomp().to!int()); )
        writeln(solve(n));
}
