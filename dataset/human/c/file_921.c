#include<stdio.h>

int main(){
  int n,a[100000],b[100000],i,j,k,cnt,max=0;
  scanf("%d",&n);
  for(i=0;i<n;i++)
    scanf("%d %d",&a[i],&b[i]);
  for(i=n;i>=1;i--){
    cnt=0;
    for(j=0;j<n;j++){
      if(cnt+n-j<i)
        break;
      if(a[j]<=i+1&&b[j]>=i+1)
        cnt++;
    }
    if(cnt>=i){
      max=i;
      break;
    }
  }
  printf("%d\n",max);
}
