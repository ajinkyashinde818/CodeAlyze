#include <stdio.h>
#include <string.h>

int main(){
  char s[110], t[110];
  scanf("%s %s", s, t);

  int table[30] = {0}, slen = strlen(s), tlen = strlen(t);
  for(int i=0; i<slen; i++)
    table[(int)s[i]-(int)'a']++;
  
  int now = 0;
  for(int i=0; i<=(int)'z'-(int)'a'; i++){
    while(table[i]){
      s[now++] = (char)(i+(int)'a');
      table[i]--;
    }    
  }

  for(int i=0; i<tlen-1; i++)
    for(int j=i+1; j<tlen; j++)
      if((int)t[i] < (int)t[j]){
	char c = t[i];
	t[i] = t[j];
	t[j] = c;
      }

  printf("%s\n", strcmp(s, t)<0 ? "Yes" : "No");

  return 0;
}
