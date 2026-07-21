#include<stdio.h>
int main(){
  int e,y,ans;
  scanf("%d %d",&e,&y);
  if(e==0 && 1989<=y && y<=2016){
    ans=y-1989;
    ans++;
    printf("H%d\n",ans);
  }else if(e==0 && 1926<=y && y<=1988){
    ans=y-1926;
    ans++;
    printf("S%d\n",ans);
  }else if(e==0 && 1912<=y && y<=1925){
    ans=y-1912;
    ans++;
    printf("T%d\n",ans);
  }else if(e==0 && 1868<=y && y<=1911){
    ans=y-1868;
    ans++;
    printf("M%d\n",ans);
  }else if(e==1){
    ans=1868+y;
    ans--;
    printf("%d\n",ans);
  }else if(e==2){
    ans=1912+y;
    ans--;
    printf("%d\n",ans);
  }else if(e==3){
    ans=1926+y;
    ans--;
    printf("%d\n",ans);
  }else if(e==4){
    ans=1989+y;
    ans--;
    printf("%d\n",ans);
  }
  return 0;
}
