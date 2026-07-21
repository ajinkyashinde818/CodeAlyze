#include<stdio.h>
int main(){
  int a,b;
  scanf("%d %d",&a,&b);
  char c[a+2][b+2];
  for(int i=0; i<a+2; i++){
    for(int j=0; j<b+2; j++){
      c[i][j]='.';
    }
  }
  for(int i=1; i<=a; i++){
    char s[b+1];
    scanf("%s",s);
    for(int j=0; j<b; j++){
      c[i][j+1]=s[j];
    }
  }
  int e=1;
  for(int i=1; i<=a; i++){
    for(int j=1; j<=b; j++){
      if(c[i][j]=='#'){
        if(c[i-1][j]=='.'&&c[i][j-1]=='.'&&c[i+1][j]=='.'&&c[i][j+1]=='.'){
          e=0;break;
        }
      }
    }
  }
  printf(e?"Yes":"No");
  return 0;}
