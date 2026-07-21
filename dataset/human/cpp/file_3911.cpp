#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <queue>
using namespace std;
class Cir{
public :
    int x,y,r;
};
class Node{
public :
    double d;int u;
    Node(double b,int a){
        u=a; d=b;
    }
    bool operator<(Node t)const{
        return d>t.d;
    }
};
int n;
Cir cs[1005];
double  dist(int x,int y){
    double temp=(long long)(cs[x].x-cs[y].x)*(cs[x].x-cs[y].x)+(long long int)(cs[x].y-cs[y].y)*(cs[x].y-cs[y].y);
    temp=sqrt(temp);
    temp=temp-cs[x].r-cs[y].r;
    if(temp<0)return 0.0;
    return  temp;
}
double  d[1005];
bool done[1005];
priority_queue<Node>Q;
int main(){
    int xs,ys,xt,yt;
    cin>>xs>>ys>>xt>>yt;
    cin>>n;
    cs[0].x=xs; cs[0].y=ys; cs[0].r=0;
    cs[1].x=xt; cs[1].y=yt; cs[0].r=0;
    for(int i=2;i<n+2;i++){
        scanf("%d%d%d",&cs[i].x,&cs[i].y,&cs[i].r);
    }
    for(int i=1;i<n+2;i++){
        d[i]=1e20;
    }
    d[0]=0;
    memset(done,0,sizeof(done));
    Q.push(Node(0.0,0));
    while(!Q.empty()){
        Node x=Q.top();Q.pop();
        int u=x.u;
        if(done[u])continue;
        done[u]=1;
        for(int i=1;i<n+2;i++){
            if(i!=u&&!done[i]){
                if(d[i]>d[u]+dist(u,i)){
                    d[i]=d[u]+dist(u,i);
                    Q.push(Node(d[i],i));
                }
            }
        }
    }
    printf("%.10lf\n",d[1]);
return 0;
}
