#include<stdio.h>
#include<string.h>
#include<math.h>
#define FOR(n) for(int i = 0;i < n;i++)
#define PRN(n) printf("%d\n",n)
#define PRS(s) printf("%s\n",s)
#define PRC(s) printf("%c",s)
int x[200000],y[200000];
int main(void){
  int n,m;
  scanf("%d %d",&n,&m);
  int a,b;
  FOR(m){
    scanf("%d %d",&a,&b);
    if(a==1)x[b]=1;
    if(b==n)y[a]=1;
  }
  FOR(n){
    if(x[i]+y[i]==2){
      PRS("POSSIBLE");
      return 0;
    }
  }
  PRS("IMPOSSIBLE");
  return 0;
}
/*
scanf("%d",&n);
scanf("%d %d",&a,&b);
*/
