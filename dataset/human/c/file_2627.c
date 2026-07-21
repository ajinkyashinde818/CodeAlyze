#include <stdio.h>
int main(){
  char a[4];
  scanf("%s",a);
  for(int i=0;i<3;i++){
    if(a[i]=='a')for(int j=0;j<3;j++){
      if(a[j]=='b')for(int k=0;k<3;k++){
        if(a[k]=='c'){
          puts("Yes");
          return 0;
        }
      }
    }
  }
  puts("No");
  return 0;
}
