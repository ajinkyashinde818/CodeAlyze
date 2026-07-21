#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void run(void){
  char *s=(char *)calloc(100000+1,sizeof(char));
  scanf("%s",s);
  int l=0;
  int r=strlen(s)-1;
  int ans=0;
  while(l<r){
    if(s[l]==s[r]){
      l++;r--;
    } else if(s[l]=='x'){
      ans++;
      l++;
    } else if(s[r]=='x'){
      ans++;
      r--;
    } else {
      printf("-1\n");
      return;
    }
  }
  printf("%d\n",ans);
}

int main(void){
  run();
  return 0;
}
