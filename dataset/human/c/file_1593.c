#include<stdio.h>
#include<string.h>
int main(){
  char s[100010],s1[100010],s2[100010]={};
  int i,r=0,c=0;
  scanf("%s",s);
  for(i=0;s[i];i++){
    if(s[i]-'x')s1[r++]=s[i];
  }
  s[i]=r=0;
  while(i--){
    if(s[i]-'x')s2[r++]=s[i];
  }
  if(strcmp(s1,s2)){
    printf("-1\n");
    return 0;
  }
  for(r=0;s[r+1];r++);
  for(i=0;s[i];i++){//printf("%c %c %d\n",s[i],s[r],c);
    if(s[i]==s[r]){
      r--;
      continue;
    }
    c++;
    if(s[i]=='x');
    else{
      r--;
      i--;
    }
  }//printf("%d\n",r);
  c+=r+1;
  printf("%d\n",c/2);
  return 0;
}
