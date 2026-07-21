#include <stdio.h>
 
int min(int x,int y){
    return x>y?y:x;
}

int max(int x,int y){
    return x>y?x:y;
}
 
int main(){
 
  int n, x=(int)1e9, y, ans=-(int)1e9, i;
 
  scanf("%d%d",&n,&y);
 
  for(i=1;i<n;i++){
    x=min(x,y);
    scanf("%d",&y);
    ans=max(ans,y-x);
  }
 
  printf("%d\n",ans);
 
  return 0;
 
}
