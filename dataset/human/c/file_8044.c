#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define rep(i,N) for(int i=0;i<(int)N;i++)
#pragma GCC optimize("O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
static inline void PUT(char c)
{
  static char buf[1<<15],*ptr=buf;
  if(ptr==buf+strlen(buf)||c==0){fwrite(buf,1,ptr-buf,stdout),ptr=buf;}*ptr++=c;
}
static inline int IN(void)
{
  int x=0,f=0,c=getchar();while(c<48||c>57){f^=c==45,c=getchar();}
  while(c>47&&c<58){x=x*10+c-48,c=getchar();}return f?-x:x;
}
static inline void OUT(int a)
{
  if(a<0)PUT('-'),a=-a;
  int d[40],i=0;do{d[i++]=a%10;}while(a/=10);
  while(i--){PUT(d[i]+48);}PUT('\n');
}
//https://atcoder.jp/contests/abc176/submissions/16116488
const int INF=2.147e9;
int qlen=0;
static inline int Abs(int x){return x<0?-x:x;}
struct nodetag{int y,x,cost;}Q[50000];
static inline void qfix(int idx)
{
  while(1)
  {
    int midx=idx;
    rep(i,2){int cidx=idx*2+i+1;if(cidx<qlen&&Q[midx].cost>Q[cidx].cost){midx=cidx;}}
    if(midx==idx){if(!idx){break;}idx=(idx-1)/2;}
    else{struct nodetag sw=Q[idx];Q[idx]=Q[midx];Q[midx]=sw;idx=midx;}
  }
}
static inline void qpush(int y,int x,int cost)
{
  Q[qlen].y=y;Q[qlen].x=x;Q[qlen].cost=cost;qfix(qlen);qlen++;
}
static inline struct nodetag qpop(void)
{
  if(qlen<=0){exit(EXIT_FAILURE);}
  struct nodetag res=Q[0];qlen--;if(qlen){Q[0]=Q[qlen];qfix(0);}
  return res;
}
const int dx[24]={0,1,0,-1,0,0,1,1,1,1,-1,-1,-1,-1,2,2,2,2,2,-2,-2,-2,-2,-2},
          dy[24]={1,0,-1,0,2,-2,1,2,-1,-2,1,2,-1,-2,0,1,2,-1,-2,0,1,2,-1,-2};
int main(void)
{
  int H=IN(),W=IN(),Ch=IN(),Cw=IN(),Dh=IN(),Dw=IN(),dist[H][W],field[H][W];char str[W+1];
  rep(i,H)
  {
    if(!scanf("%s",str)){return -1;}
    rep(j,W){dist[i][j]=INF;field[i][j]=(str[j]=='#');}
  }
  qpush(Ch-1,Cw-1,0);dist[Ch-1][Cw-1]=0;
  while(qlen)
  {
    struct nodetag pos=qpop();
    rep(i,24)
    {
      int ny=pos.y+dy[i],nx=pos.x+dx[i],warp=!(Abs(dx[i])+Abs(dy[i])<=1),need=dist[pos.y][pos.x]+warp;
      if(0<=ny&&ny<H&&0<=nx&&nx<W&&!field[ny][nx]&&need<dist[ny][nx])
      {
        dist[ny][nx]=need;qpush(ny,nx,need);
      }
    }
  }
  return OUT(dist[Dh-1][Dw-1]<INF?dist[Dh-1][Dw-1]:-1),0;
}
