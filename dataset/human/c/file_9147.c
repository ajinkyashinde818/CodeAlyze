#include <stdio.h>

int main(){
  int n,k,count=0;
  int data[10000000];
  scanf("%d %d",&n,&k);
  
  for(int i=0;i<n;i++){
    scanf("%d",&data[i]);
  }
  for(int i=0;i<n;i++){
    if(data[i]>=k){
      count++;
    }
  }
  printf("%d",count);
}
