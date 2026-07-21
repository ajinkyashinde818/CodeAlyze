#include<stdio.h>
int main(){
  char text[3];
  scanf("%s",text);

  if(text[0]==text[1]){
    printf("No");
  }else if(text[1]==text[2]){
    printf("No");
  }else if(text[2]==text[0]){
    printf("No");
  }else{
    printf("Yes");
  }
}
