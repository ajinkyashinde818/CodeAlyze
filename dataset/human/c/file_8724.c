#include<stdio.h>
int main(){
  int n,i,c=0;
  int a[1000000],use[1000000];
  scanf("%d",&n);
  for(i=1;i<=n;i++){
    scanf("%d",&a[i]);
  }
  i=1;
  while(use[i]==0){
    use[i]=1;
    i=a[i];
    c++;
    if(i==2){
      printf("%d\n",c);
      return 0;
    }
  }
  puts("-1");
  return 0;
}
