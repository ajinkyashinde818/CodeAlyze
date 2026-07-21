#include<stdio.h>

int main()
{
 int N;
 int M;
 int i;
 int j;
 int a[200005];
 int b[200005];
 int connect1[200005];
 int connectN[200005];
 int path=0;

 scanf("%d %d",&N, &M);

 for(i=0; i<N; i++) connect1[i]=0;
 for(i=0; i<N; i++) connectN[i]=0;
 for(i=0;i<M;i++) 
 {
   scanf("%d %d",&a[i],&b[i]);
   if (a[i] == 1) connect1[b[i]]=1;
   if (b[i] == N) connectN[a[i]]=1;
 }
 for(i=0; i<N; i++)
 {
  if((connect1[i]==1)&(connectN[i]==1)) path=1;
 }

 if (path==1)
 {
  printf("POSSIBLE\n");
 }else{
  printf("IMPOSSIBLE\n");
 }

return 0;
}
