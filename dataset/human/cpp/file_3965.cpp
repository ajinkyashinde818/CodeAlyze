#include<queue>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

void Read(int &p)
{
	p=0;
	int f=1;
	char c=getchar();
	while(c<'0' || c>'9')
	{
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0' && c<='9')
		p=p*10+c-'0',c=getchar();
	p*=f;
}

const int MAXN=1000+24;
int N,x[MAXN],y[MAXN],r[MAXN],vis[MAXN];
double Dis[MAXN];
#define ids(i,j) max(0.0,sqrt(1.0*(x[i]-x[j])*(x[i]-x[j])+1.0*(y[i]-y[j])*(y[i]-y[j]))-r[i]-r[j])

bool inq[MAXN];
int showup[MAXN];
int Spfa()
{
	int s=1,t=2;
    queue<int>Q;
    for(int i=1;i<=N;i++) Dis[i]=(i==s)?0:4000000000.0;
    Q.push(s),inq[s]=1,showup[s]++;

    int p;

    while(!Q.empty())
    {
        p=Q.front(),Q.pop(),inq[p]=0;
        for(int i=1;i<=N;i++)
            if(Dis[i]>ids(p,i)+Dis[p])
            {
                Dis[i]=ids(p,i)+Dis[p];
                if(!inq[i])
                {
                    Q.push(i),inq[i]=1,showup[i]++;
                    if(showup[i]>N) return -1;
                }
            }
    }
    if(Dis[t]==4000000000.0) return -2;
    return Dis[t];
}
int main()
{
	Read(x[1]); Read(y[1]); Read(x[2]); Read(y[2]);
	Read(N),N+=2;
	for(int i=3;i<=N;i++)
		Read(x[i]),Read(y[i]),Read(r[i]);
	Spfa();
	printf("%.10lf",Dis[2]);
}
