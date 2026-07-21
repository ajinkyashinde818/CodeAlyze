#include<stdio.h>

void check(char *,char *,char *);

int main(){
  int H,W,ans=0;
  scanf("%d%d",&H,&W);
  getchar();
  char s[H][W];
  for (int i = 0; i < H; i++){
    for (int j = 0; j < W; j++){
      scanf("%c",&s[i][j]);
    }
    getchar();
  }

  for (int i = 0; i < H-1; i++){
      for (int j = 0; j < W-1; j++){
        if (s[i][j]!='.'){ check(&s[i][j],&s[i][j+1],&s[i+1][j]); }
        if (s[i+1][j+1]!='.'){ check(&s[i+1][j+1],&s[i+1][j],&s[i][j+1]); }
      }
  }
  
  for (int i = 0; i < H; i++){
    for (int j = 0; j < W; j++){
      if(s[i][j]=='#'){
        ans = 1;
      }
    }
  }

  ans > 0 ? puts("No") : puts("Yes"); 

  return 0;
}

void check(char *a,char *b,char *c){
  if (*b!='.'){ *a='1'; *b='1';}
  if (*c!='.'){ *a='1'; *c='1';}
}
