#include<stdio.h>
int main(){
  int n,i,j,d[110];
  char s[110],c[60];
  for(i=0;i<26;i++)c[i   ]=i+'a';
  for(i=0;i<26;i++)c[i+26]=i+'A';
  while(scanf("%d",&n),n){
    for(i=0;i<n;i++)scanf("%d",&d[i]);
    scanf("%s",s);
    for(i=0;s[i];i++){
      for(j=0;c[j]-s[i];j++);
      printf("%c",c[(j-d[i%n]+52)%52]);
    }
    printf("\n");
  }
  return 0;
}
