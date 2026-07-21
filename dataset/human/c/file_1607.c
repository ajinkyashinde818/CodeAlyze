#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(void){
  char s[100000];
  int c=0, r, l;
  scanf("%s",s);
  r = strlen(s)-1;  l=0;
  while(l<=r){
    while(s[l]=='x'){
      if(s[r]=='x'){r--;  l++;}
      else{c++; l++;}
    }
    while(s[r]=='x'){
      c++; r--;
    }
    if(s[l]!=s[r]) break;
    else{l++; r--;}
  }
  if(l<=r) printf("-1\n");
  else printf("%d\n",c);
  return 0;
}
