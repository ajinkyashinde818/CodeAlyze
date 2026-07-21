#include<stdio.h>

int main(){
  int k,n,i;
  int max=0,first,tmp,tm;
  scanf("%d",&k);
  scanf("%d",&n);
  for(i=0;i<n;i++){
  scanf("%d",&tmp);
    if(i==0)first=tm=tmp;  
    else{
      
      if(max<(tmp-tm)){
       max = tmp-tm; 
      }
      tm = tmp;
    }
  }
  if(max < (first+(k-tmp)))max = first+(k-tmp);
  printf("%d\n",k-max);
 return 0; 
}
