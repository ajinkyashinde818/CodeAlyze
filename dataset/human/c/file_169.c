#include<stdio.h>
#include<stdlib.h>
  
int main(){
  int n,m;
  scanf("%d%d",&n,&m);
  int input[m], flag[n+1];
  int i;
  for(i=0;i<m;i++){
    scanf("%d",&input[i]);
  }
  
  for(i=0;i<n+1;i++){
    flag[i]=0;
  }

  for(i=m-1;i>=0;i--){
    if(flag[input[i]]==0){
      printf("%d\n",input[i]);
      flag[input[i]]=m-i;
    }
  }
  for(i=1;i<=n;i++){
    if(flag[i]==0){
      printf("%d\n",i);
    }
  }
  return 0;
}
