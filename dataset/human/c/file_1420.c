#include <stdio.h>
int main(void) {
char str[2];
 scanf("%2s",str);
if(str[0]=='9'||str[1]=='9'){
  printf("Yes\n");
}if(str[0]!='9'&&str[1]!='9'){
  printf("No\n");
}
	return 0;
}
