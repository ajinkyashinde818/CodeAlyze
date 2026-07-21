#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

int main(){
    int k,s;
    int ans = 0;
    int x,y;
    scanf("%d %d",&k,&s);
  
  for(x=0;x<=k;x++){
    for(y=0;y<=k;y++){
        if((s-(x+y) <= k) && (x+y <= s)){
          ans += 1;
        }
      }
    }
printf("%d",ans);
return 0;
}
