#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(int argc, char const *argv[]) {
  int i,j,k,l,n,m;
  char s[50][51]={{'\0'}};
  char tmp[50][51]={{'\0'}};
  int x=0,y=0,not=0,match=0;

  scanf("%d %d",&n,&m );


  for(i=0;i<n;i++) scanf("%s",s[i] );
  for(i=0;i<m;i++) scanf("%s",tmp[i] );

  for(i=0;i < n - m + 1;i++){
    for(j=0;j < n - m + 1;j++){
      if( s[i][j] == tmp[0][0]){
        not = 0;
        x = j; y = i;
        for(k=0,y=i;k < m && not!=1;k++,y++){
          for(l=0,x=j;l < m && not!=1;l++,x++){
            //printf("%d %d %d %d %c %c\n",x,y,k,l,s[y][x],tmp[k][l]);
            //printf("%c\n",s[y][x] );
            //printf("%c\n",tmp[k][l] );
            if(s[y][x] != tmp[k][l]){
              not=1;
              break;
            }
          }
        }
        if(not != 1){
          puts("Yes");
          return 0;
        }
      }
    }
  }

  puts("No");
  return 0;
}
