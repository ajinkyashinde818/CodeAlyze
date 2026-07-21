#include<stdio.h>
int main(void)
{
  int n,a,b,c=0,f=0,i; 
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d%d",&a,&b);
    if(a==b){
      c++;
    }
    else{
      c=0;
    }
    if(c>=3){
      f=1;
    }
  }
  if(f==1){
    printf("Yes\n");
  }
  else{
    printf("No\n");
  }
  return 0;
}
