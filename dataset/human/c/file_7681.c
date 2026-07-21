#include<stdlib.h>
#include<stdio.h>

int main(){
  int k,j=0;
  int set[10000];
  while(1){
    int i;
    scanf("%d",&i);
    if(i==0){
      break;
    }else{
      set[j]=i;
      j++;
    }    
  }
  for(k=0;k<j;k++){
    printf("Case %d: %d\n",k+1,set[k]);
  }
  return 0;
}
