import std;

// dfmt off
T lread(T=long)(){return readln.chomp.to!T;}
T[] lreads(T=long)(long n){return generate(()=>readln.chomp.to!T()).take(n).array;}
T[] aryread(T=long)(){return readln.split.to!(T[]);}
void arywrite(T=long)(T[] ary){ary.map!(text).join(' ').writeln;}
void scan(TList...)(ref TList Args){auto line = readln.split;
foreach (i,T;TList){T val=line[i].to!(T);Args[i]=val;}}
void dprint(TList...)(TList Args){debug{auto s=new string[](TList.length);
static foreach(i,a;Args) s[i]=text(a);s.map!(text).join(' ').writeln;}}
alias sread=()=>readln.chomp();enum MOD =10^^9+7;
alias PQueue(T,alias less="a<b") = BinaryHeap!(Array!T,less);
// dfmt on

void main()
{
    long N, K;
    scan(N, K);
    auto A = aryread();
    A[] -= 1;
    long k;
    auto loop = new long[][](N);
    long p;
    while (k < K)
    {
        dprint(k, p);
        if (loop[p].length == 0)
        {
            loop[p] ~= k;
            k++;
            p = A[p];
            continue;
        }
        loop[p] ~= k - loop[p][0];
        dprint(loop[p]);
        long ok = 1;
        long ng = loop[p].length;
        while (1 < ng - ok)
        {
            long m = (ok + ng) / 2;
            if (loop[p][m] <= (K - k))
            {
                ok = m;
            }
            else
            {
                ng = m;
            }
        }
        if (loop[p][ok] <= (K - k))
        {
            k += loop[p][ok];
            continue;
        }
        else
        {
            k++;
            p = A[p];
            continue;
        }
    }
    writeln(p + 1);
}
