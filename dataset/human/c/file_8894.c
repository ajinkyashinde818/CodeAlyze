#include<stdio.h>

int main(void){
  int h=0, w=0;
  char s[60][60];
  int dx[4]={1, -1, 0, 0};
  int dy[4]={0, 0, 1, -1};
  int ans=1, flag=0;
  int i=0, j=0, k=0;
  int i2=0, j2=0;

  scanf("%d %d", &h, &w);

  for(i=0; i<h; i++){
    scanf("%s", &s[i]);
  }

  for(i=0; i<h; i++){
    for(j=0; j<w; j++){
      if(s[i][j]=='#'){
        flag=0;
        for(k=0; k<4; k++){
          i2=i+dx[k];
          j2=j+dy[k];
          if(i2>=0 && i2<h &&
            j2>=0 && j2<w && s[i2][j2]=='#'){
              flag=1;
            }
         }
         if(!flag)
          ans=0;
      }
    }
  }

if(ans==1)
  printf("Yes\n");
else
  printf("No\n");

  return 0;
}
