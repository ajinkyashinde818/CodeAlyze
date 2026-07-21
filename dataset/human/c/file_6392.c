#include<stdio.h>
int main(){
  int maxv,min,n,ans;
  scanf("%d",&n);
  if(n<2||n>2000001)return 0;
  int i,a;
  for(i=0;i<n;i++){
    scanf("%d",&a);
    if(a<0||a>1000000001)return 0;
    if(i==1)maxv=a-min;
    if(i==0){min=a;
      continue;
    }
    if(a-min>maxv)maxv=a-min;
    if(a<min)min=a;
  }
      printf("%d\n",maxv);
  return 0;
}
