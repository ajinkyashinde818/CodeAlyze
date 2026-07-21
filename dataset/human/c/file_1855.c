#include <stdio.h>

int main(){
  int n;
  int sum=0;
  scanf("%d",&n);
  int i;
  int a[n+1];
  int b[n+1];
  int c[n];
  int k;
  for(i=1;i<=n;i++){
  scanf("%d",&a[i]);
}
for(i=1;i<=n;i++){
  scanf("%d",&k);
  b[i]=k;

  sum+=k;

  }
  for(i=1;i<n;i++){
    scanf("%d",&c[i]);
  }
  for(i=1;i<n;i++){
    if(a[i]==a[i+1]-1){
      sum+=c[a[i]];
    }

  }
  printf("%d\n",sum);
}
