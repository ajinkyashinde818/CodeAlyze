/*
  C - 白昼夢 / Daydream
  <http://abc049.contest.atcoder.jp/tasks/arc065_a>
  ・ヌル文字('\0')とヌルポインタ(NULL)は違う。<http://www.kis-lab.com/serikashiki/C/C01.html>
*/

#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[]) {

  char S[100001];
  char str[4][8] = {"dream", "dreamer", "erase", "eraser"};
  char tmp;
  int len;
  int i, j;
  int pt;

  scanf("%s", S);

  len = strlen( S );
  for( j=0; j<len/2; j++){
    tmp = S[j];
    S[j] = S[len-1-j];
    S[len-1-j] = tmp;
  }

  for( i=0; i<4; i++ ){
    len = strlen( str[i] );
    for( j=0; j<len/2; j++ ){
      tmp = str[i][j];
      str[i][j] = str[i][len-1-j];
      str[i][len-1-j] = tmp;
    }
  }

  pt = 0;
  while( S[pt] != '\0'){
    i = 0;
    while( i<4 ){
      len = strlen(str[i]);
      j = 0;
      while( j<len ){
          if( S[pt+j] == str[i][j] ){
            j++;
          }else{
            break;
          }
      }
      if( j==len ){
        pt += len;
        break;
      }
      if( i==3 ){
        printf("NO");
        return 0;
      }else{
        i++;
      }
    }
  }
  printf("YES");
  return 0;

}
