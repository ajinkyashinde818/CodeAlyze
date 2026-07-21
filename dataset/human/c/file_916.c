#include<stdio.h>
int main(){
  int n,i,a,b,max,s,d[1000010];
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d %d",&a,&b);
    d[a]++;
    d[b+1]--;
  }
  s=1;
  for(i=max=0;i<n+2;i++){
    s+=d[i];//printf("%d ",s);
    if(max<s&&i<=s)max=i;
  }//printf("\n");
  printf("%d\n",max-1);
  return 0;
}
