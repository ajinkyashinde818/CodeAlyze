#include <stdio.h>
#include <string.h>
const int MOD=1000000007;
struct mat
{
    long long val[4][4];
};
mat mul(const mat &a,const mat &b)
{
    mat ret;
    memset(ret.val,0,sizeof(ret.val));
    for (int i=0;i<4;++i)
        for (int j=0;j<4;++j)
            for (int k=0;k<4;++k)
                ret.val[i][k]+=a.val[i][j]*b.val[j][k];
    for (int i=0;i<4;++i)
        for (int j=0;j<4;++j)
            ret.val[i][j]%=MOD;
    return ret;
}
mat notbad[30],bad;
int main()
{
    notbad[0]=(mat){{{1,0,0,1},{1,1,0,1},{1,0,1,1},{1,1,1,2}}};
    bad=(mat){{{1,0,0,0},{1,1,0,0},{1,0,1,0},{1,1,1,1}}};
    for (int i=1;i<30;++i)
        notbad[i]=mul(notbad[i-1],notbad[i-1]);
    mat init=(mat){{{1,0,0,0},{0,1,0,0},{0,0,1,0},{0,0,0,1}}};
    int n,m;
    scanf("%d%d",&n,&m);
    int last=-1;
    for (int i=0;i<m;++i)
    {
        int cur;
        scanf("%d",&cur);
        int pw=cur-last-1,bits=0;
        while (pw)
        {
            if (pw&1)
                init=mul(notbad[bits],init);
            ++bits;
            pw>>=1;
        }
        init=mul(bad,init);
        last=cur;
    }
    int pw=n-last-1,bits=0;
    while (pw)
    {
        if (pw&1)
            init=mul(notbad[bits],init);
        ++bits;
        pw>>=1;
    }
    printf("%lld\n",init.val[3][0]);
    return 0;
}
