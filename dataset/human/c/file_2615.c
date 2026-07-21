#include <stdio.h>

int main(){
  char s[4];
  int ans[3] = {};
  int i;
  scanf("%s",s);
  for(i = 0;i < 3;i++){
    switch(s[i]){
      case 'a':
        ans[0] = 1;
        break;
      case 'b':
        ans[1] = 1;
        break;
      case 'c':
        ans[2] = 1;
    }
  }
  if(ans[0] == 1 && ans[1] == 1 && ans[2] == 1){
    printf("Yes\n");
  }else{
    printf("No\n");
  }
  return(0);
}
