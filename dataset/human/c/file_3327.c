#include <stdio.h>

bool ans=false;
int dn[4]={5,7,5,6};
char s[100001],d[4][10]={"dream","dreamer","erase","eraser"};

void h(int x);

int main(void){
  scanf("%s",s);
  h(0);
  printf("%s\n",(ans)? "YES":"NO");
  return 0;
}

void h(int x){
  int i,j;
  if (ans) return;
  if (!s[x]){
    ans=true;
    return;
  }
  for (i=0;i<4;i++){
    for (j=0;j<dn[i];j++){
      if (s[x+j]!=d[i][j]) break;
    }
    if (j==dn[i]) h(x+j);
  }
  return;
}
