#include <stdio.h>
 int change(char);
int main(){
char c1,d1,s;
  scanf("%c%c%c",&c1,&s,&d1);
  
  int c =change(c1);
  int d = change(d1);
 
  if(c>d){
printf(">");
  }else if(c<d){
    printf("<");
  }else if(c = d){
    printf("=");
  }
  return 0;
}

int change(char i){
  if(i=='A'){
    return 65;
  }else if(i=='B'){
    return 66;
  }else if(i=='C'){
    return 67;
  }else if(i=='D'){
    return 68;
  }else if(i=='E'){
    return 69;
  }else if(i=='F'){
    return 70;
  }
}
