#include<stdio.h>

int main(){
  int n,a[21],b[21],c[21],i,sum=0,v[21]={0};
  a[0]=10000;
  scanf("%d",&n);
  for(i=1;i<=n;i++){
    scanf("%d",&a[i]);
   if(a[i]==a[i-1]+1){
     v[a[i-1]]++;
   }
  }
  for(i=1;i<=n;i++){
    scanf("%d",&b[i]);
    sum+=b[i];
  }
  
  for(i=1;i<n;i++){
    scanf("%d",&c[i]);
    if(v[i]!=0){
      sum+=c[i];
    }
  }

  printf("%d\n",sum );
  return 0;
}
