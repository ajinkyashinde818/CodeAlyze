#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <utility>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <functional>

using namespace std;

#define int long long
#define MP make_pair
#define PB push_back
#define FI first
#define SE second
typedef pair<int, pair<int, int> > PPII;
typedef pair<int, int> PII;
static const int INF = 1ll<<60;


int N;
PII Start,End;
vector<PPII> V;
double d[1005];

void dijkstra(){
    fill(d,d+1005,INF);
    priority_queue<PII,vector<PII>,greater<PII> > que;
    que.push(PII(0,0));
    d[0]=0;
    while(!que.empty()){
        PII p=que.top();
        que.pop();
        int v=p.SE;
        //cout<<v<<endl;
        if(d[v]<p.FI)continue;
        for(int i=0;i<V.size();++i){
            double di=sqrt(abs(V[v].FI-V[i].FI)*abs(V[v].FI-V[i].FI)+abs(V[v].SE.FI-V[i].SE.FI)*abs(V[v].SE.FI-V[i].SE.FI));
            double cost=max(di-(V[i].SE.SE+V[v].SE.SE),0.0);
            if(d[i]>d[v]+cost){
                d[i]=d[v]+cost;
                que.push(PII(d[i],i));
            }
        }
    }
}

signed main(){
    cin>>Start.FI>>Start.SE>>End.FI>>End.SE;
    V.PB(PPII(Start.FI,MP(Start.SE,0)));
    V.PB(PPII(End.FI,MP(End.SE,0)));
    cin>>N;
    for(int i=0;i<N;++i){
        int x,y,r;
        cin>>x>>y>>r;
        V.PB(PPII(x,MP(y,r)));
    }
    dijkstra();
    printf("%.10lf\n",d[1]);
    return 0;
}
