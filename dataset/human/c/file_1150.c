#include <stdio.h>
#include <string.h>

int main(void){
  char s[101], t[101], tmp;
  int ls, lt, i, j;
  
  scanf("%s %s", s, t);

  ls = strlen(s);
  lt = strlen(t);
 
  for( i = 0; i < ls; i++){
    for( j = i+1; j < ls; j++){
      if(s[i] > s[j]){
	tmp = s[i];
	s[i] = s[j];
	s[j] = tmp;
      }
    }
  }
  for( i = 0; i < lt; i++){
    for( j = i+1; j < lt; j++){
      if(t[i] < t[j]){
	tmp = t[i];
	t[i] = t[j];
	t[j] = tmp;
      }
    }
  }

  if(strcmp(s, t) < 0) printf("Yes");
  else printf("No");
  return 0;
  
 
  
}
