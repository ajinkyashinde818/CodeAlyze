#include<stdio.h>
int main(void){
  char s[3];
  int x=0;
  scanf("%s",s);
  
  for(int j=0;j<3;j++){
    if(s[j]=='a'){
      x+=1;
    }
    else if(s[j]=='b'){
      x+=2;
    }
    else if(s[j]=='c'){
      x+=3;
    }
  }

  if(x==6){
    printf("Yes");
  }
  else
    printf("No");
 return 0;
}
