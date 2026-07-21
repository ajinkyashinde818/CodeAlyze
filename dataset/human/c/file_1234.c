#include <stdio.h>
#include <string.h>

int main(){

  char s[120], t[120], tmp[3];
  int len_s, len_t, i, j, c;

  scanf("%s %s", s, t);

  len_s = strlen(s);
  len_t = strlen(t);

  for(i=0; i<len_s; i++){
    c=i;
    for(j=i; j<len_s; j++){
      if(s[j]<s[c]) c=j;
    }
    tmp[0] = s[i];
    s[i] = s[c];
    s[c] = tmp[0];
  }

  for(i=0; i<len_t; i++){
    c=i;
    for(j=i; j<len_t; j++){
      if(t[j]>t[c]) c=j;
    }
    tmp[0] = t[i];
    t[i] = t[c];
    t[c] = tmp[0];
  }

  if(strcmp(s,t)<0) puts("Yes");
  else puts("No");

  return 0;
}
