#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int cmpChar(char *pchar){
  
  if(strlen(pchar) == 0) return 0;
  
  int rc = 0;
  if(memcmp(pchar, "dreamer", 7) == 0){
    rc = cmpChar(pchar + 7);
    if(rc == 0) return rc;
  }  
  if(memcmp(pchar, "dream", 5) == 0){
    rc = cmpChar(pchar + 5);
    if(rc == 0) return rc;
  }
  if(memcmp(pchar, "eraser", 6) == 0){
    rc = cmpChar(pchar + 6);
    if(rc == 0) return rc;
  }
  if(memcmp(pchar, "erase", 5) == 0){
    rc = cmpChar(pchar + 5);
    if(rc == 0) return rc;
  }
  
  return -1;
}

int main(void){
  char buf[131072] = { 0 };
  
  fgets(buf, sizeof(buf), stdin);
  // 改行チェック
  char *tok = strtok(buf, "\n"); 
  
  int rc = cmpChar(tok);
  if(rc == 0) printf("YES\n");
  else printf("NO\n");
  
  return 0;
}
