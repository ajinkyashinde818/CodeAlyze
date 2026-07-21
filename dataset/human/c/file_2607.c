#include <stdio.h>
int main() {
  char moji[4];
  int a,b,c = 0;
  gets(moji);
  for(int i=0; i<3; i++){
	if(moji[i] == 'a') a += 1;
    if(moji[i] == 'b') b += 1;
    if(moji[i] == 'c') c += 1;
  }
  if(a==1 && b==1 && c==1) printf("Yes\n");
   else printf("No\n");
return 0;
}
