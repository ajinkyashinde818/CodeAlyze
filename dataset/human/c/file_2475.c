#include <stdio.h>

int main(void){
  char s[3];
  int a[3]={0,0,0};
  int i;
  scanf("%s",s);
  for(i=0;i<3;i++){
    if(s[i]=='a'){
      a[0]++;
    }
    if(s[i]=='b'){
      a[1]++;
    }
    if(s[i]=='c'){
      a[2]++;
    }
  }
  if(a[0]==1 && a[1]==1 && a[2]==1)
    printf("Yes");
  else
    printf("No");
  
  return 0;
}
