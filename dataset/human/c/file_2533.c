#include<stdio.h>
int main(){
  char s[5];
  int a=0,b=0,c=0,i;
  scanf("%s", s);
  for(i=0;i<3;i++){
    switch(s[i]){
    case 'a': a=1;break;
    case 'b': b=1;break;
    case 'c': c=1;break;
    }
  }
  if(a==1 && b==1 && c==1)puts("Yes");
  else puts("No");
  return 0;
}
