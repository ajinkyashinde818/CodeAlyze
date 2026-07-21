#include <stdio.h>
 
#define rep(i,n) for(int i=0;i<(int)n;++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)
int dx[]={0,1,0,-1},dy[]={1,0,-1,0};
 
typedef struct{
  short x,y;
  int cost;
  short ch;
}mouse;
const int MAX=(1<<14)-1;
mouse que[(1<<14)-1];
int s,num;
 
mouse t;
short cx,cy,nx,ny,ch,nch,h,w,n;
int cost;

char ku[1000][1001];

main(){
  scanf("%d%d%d ",&h,&w,&n);
  short maxch[h][w];
  int i,j;
  
  for(i=0;i<h;i++)fread(ku[i],1,w+1,stdin);
 
 
  for(i=0;i<h;i++)for(j=0;j<w;j++){
    if(ku[i][j]=='S')cx=i,cy=j;
    maxch[i][j]=-1;
  }
 
 
  que[s+num++]=(mouse){cx,cy,0,0};
  maxch[cx][cy]=0;
 
  while(1){
    t=que[s++&MAX];
    num--;
    cx=t.x,cy=t.y,cost=t.cost;
    ch=t.ch;
 
    for(i=0;i<4;i++){
      nx=cx+dx[i],ny=cy+dy[i];
      if(nx<0 || nx>=h || ny<0 || ny>=w)continue;
      if(ku[nx][ny]=='X')continue;
      nch=ch;
      if(ku[nx][ny]<='9' && ku[nx][ny]>='1' && ku[nx][ny]-'0'==t.ch+1){
        nch=ch+1;
      }
 
      if(maxch[nx][ny]>=nch)continue;
      if(nch==n){
        printf("%d\n",cost+1);
        return 0;
      }
      maxch[nx][ny]=nch;
      que[s+num++&MAX]=(mouse){nx,ny,cost+1,nch};
    }
  }
}
