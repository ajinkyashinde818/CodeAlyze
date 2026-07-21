#include <stdio.h>
#include <string.h>

#define MAXSIZE 100000

void reverse(char *);
int isMatched(const char *, const char *);

int main(){
  int i, j = 0, count = 0;
  int status = 1;
  char s[MAXSIZE];
  char test[4][8];
  strcpy(test[0], "dream");
  strcpy(test[1], "dreamer");
  strcpy(test[2], "erase");
  strcpy(test[3], "eraser");
  char temp;

  // get and reverse
  scanf("%s", s);
  reverse(s);
  for(i = 0; i < 4; i++){
    reverse(test[i]);
  }
  
  while(status){
    status = 0;
    for(i = 0; i < 4; i++){
       if(!strncmp(&s[count], test[i],strlen(test[i]))){
        count += strlen(test[i]);
        status = 1;
        break;
      }
    }
  }

  printf("%s\n", (count==strlen(s)) ? "YES": "NO" );
  

  return 0;
}

void
reverse(char *str){
  int i;
  char temp;
  for(i = 0; i < strlen(str)/2; i++){
    temp = str[i];
    str[i] = str[strlen(str) -1 -i];
    str[strlen(str) - 1 - i] = temp;
  }
}
