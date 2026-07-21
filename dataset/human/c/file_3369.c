#include<stdio.h>
int main(){
  char *w[4]={"dreamer","dream","eraser","erase"};
  char s[100001];
  int i=0,j,k,l;
  scanf("%s",s);
  while(s[i]!='\0'){
    l=k=0;for(j=0;w[l][j]!='\0';j++)k+=w[l][j]==s[i+j];
    if(j==k&&s[i+j]!='a'){l=4;i+=j;}
    l++;
    while(l<4){
      k=0;for(j=0;w[l][j]!='\0';j++)k+=w[l][j]==s[i+j];
      if(j==k){l=5;i+=j;}
      l++;
    }
    if(l==4){printf("NO");return 0;}
  }
  printf("YES");
}
