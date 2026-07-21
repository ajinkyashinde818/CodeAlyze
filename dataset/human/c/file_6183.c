#include<stdio.h>

int main(void)
{
 int N;
 scanf("%d",&N);
 int num[N];
 int i;
 for(i=0;i<N;i++) scanf("%d", &num[i]);
  int maxv=-1000000000;
  int minv=num[0];
  for(i=1;i<N;i++){
    if(maxv<num[i]-minv) maxv=num[i]-minv;
    if(minv>num[i]) minv=num[i];
 }
 printf("%d\n",maxv);
 return 0;
}
