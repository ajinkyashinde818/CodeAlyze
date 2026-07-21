#include<stdio.h>
#define rep(i,n) for(i=0;i<n;i++)
#define MAX 1000
const int QMAX = MAX*MAX;
typedef struct{unsigned short x,y;int h;char c;}P;
char Dx[]={1,0,-1,0},Dy[]={0,1,0,-1};
P q[MAX*MAX],p;
int main(void)
{
  int h,w,n,i,j,x,y,hp,tp,xx,yy,mc;
  char f[MAX][MAX],cost[MAX][MAX]={0};
  scanf("%d%d%d",&h,&w,&n);
  rep(i,h)rep(j,w){
    scanf(" %c",f[i]+j);
    if(f[i][j]=='S'){
      x=j; y=i;
    }
  }
  mc=1;hp=tp=0;q[tp++]=(P){x,y,0,1};
  while(hp!=tp){
    p=q[hp++];if(hp==QMAX)hp=0;
    if(mc>p.c)continue;
    if(p.c==n+1)break;
    rep(i,4){
      xx=p.x+Dx[i]; yy=p.y+Dy[i];
      if(xx>=0&&xx<w&&yy>=0&&yy<h&&cost[yy][xx]<p.c&&f[yy][xx]!='X'){
        cost[yy][xx]=p.c;
        if(f[yy][xx]-'0'==p.c){
          mc=p.c+1;
          q[tp++]=(P){xx,yy,p.h+1,p.c+1};
        }
        else{
          q[tp++]=(P){xx,yy,p.h+1,p.c};
        }
        if(tp==QMAX)tp=0;
      }
    }
  }
  printf("%d\n",p.h);
  return 0;
}
