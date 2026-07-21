#include<stdio.h>
int n,m;
int t[200001];
 
int u[200001];
 
int main(){
  int i;
   
  scanf("%d %d",&n,&m);
   
  for(i=0;i<m;i++){
    scanf("%d",&t[i]);
  }
   
  for(i=m-1;i>=0;i--){
    int num=t[i];
    if( u[num] == 0 ){
      printf("%d\n",num);
      u[num]=1;
    }
  }
 
  for(i=1;i<=n;i++){
    if(u[i]==0){
      printf("%d\n",i);
      u[i]=1;
    }
  }
  return 0;
}
