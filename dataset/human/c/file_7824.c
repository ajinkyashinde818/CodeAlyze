#include<stdio.h>
int main()
{
  int n,k,p;
  

  scanf("%d",&n);
    
  while(n-->0){
    scanf("%d%d",&k,&p);
    
    if(k%p==0){
      printf("%d\n",p);

    }else if(k>p){
      printf("%d\n",k%p);

    }else if(k<p){
      printf("%d\n",k); 
    }}
    
    return 0;
}
