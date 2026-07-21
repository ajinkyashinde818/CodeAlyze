#include <stdio.h>
#include <string.h>


int main(){
  char s[100],t[100];
  int sl,tl,x,y,tmp,i,j;
  y=0;
  scanf("%s",s);
  scanf("%s",t);
  sl = strlen(s);
  tl = strlen(t);
  if(sl > tl){
    x = tl;
  }else{
    x = sl;
  }
  for(i=0;i<sl;i++){
    for(j=i+1;j<sl;j++){
      if(s[i] > s[j]){
        tmp = s[j];
        s[j] = s[i];
        s[i] = tmp;
      }
    }
  }
  for(i=0;i<tl;i++){
    for(j=i+1;j<tl;j++){
      if(t[i] < t[j]){
        tmp = t[j];
        t[j] = t[i];
        t[i] = tmp;
      }
    }
  }
  for(i=0;i<x;i++){
    if(s[i]<t[i]){
      printf("Yes\n");
      break;
    }else if(s[i]>t[i]){
      printf("No\n");
      break;
    }else if(s[i]==t[i]){
      y += 1;
    }
  }
  if(y==x){
    if(tl > sl){
      printf("Yes");
    }else{
      printf("No");
    }
  }
  return 0;
}
