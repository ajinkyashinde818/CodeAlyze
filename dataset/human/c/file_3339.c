#include <stdio.h>
#include <string.h>

int main(void){
  char S[100000];
  int T[100000] = {0};
  int counter = 1;
  scanf("%s",S);
  int i,j;

  for(i=0;i<strlen(S);i++){
    if(S[i] == 'e' &&S[i+1] == 'r'&&S[i+2] == 'a'&&S[i+3] == 's'&&S[i+4] == 'e'&&S[i+5] == 'r'){
      for(j=0;j<=5;j++){ T[i+j] = 1;}
      }else if(S[i] == 'e' &&S[i+1] == 'r'&&S[i+2] == 'a'&&S[i+3] == 's'&&S[i+4] == 'e'){
        for(j=0;j<=4;j++){ T[i+j] = 1; }
      }else if(S[i] == 'd' &&S[i+1] == 'r'&&S[i+2] == 'e'&&S[i+3] == 'a'&&S[i+4] == 'm'&&S[i+5] == 'e'&&S[i+6] == 'r'){
        for(j=0;j<=6;j++){ T[i+j] = 1; }
        }else if(S[i] == 'd' &&S[i+1] == 'r'&&S[i+2] == 'e'&&S[i+3] == 'a'&&S[i+4] == 'm'){
          for(j=0;j<=4;j++){ T[i+j] = 1; }
        }
      }

    for(i=0;i<strlen(S);i++){
      counter *= T[i];
    }
    if(counter == 1){
      printf("YES\n");
    }else printf("NO\n");

    return 0;
}
