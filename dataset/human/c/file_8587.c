#include<stdio.h>
#include<stdbool.h>
int main(){
  int n;
  int button[100005];
  int index=1;
  int cnt=1;
  bool flag[100005]={false};
  bool ans=false;
  int i;
  scanf("%d",&n);
  for(i=1;i<=n;i++){
    scanf("%d",&button[i]);
  }
  while(flag[index]==false&&ans==false){
    if(button[index]==2){
      ans=true;
    }else{
      flag[index]=true;
      index=button[index];
      cnt++;
    }
  }
  if(ans){
    printf("%d\n",cnt);
  }else{
    printf("-1\n");
  }
  return(0);
}
