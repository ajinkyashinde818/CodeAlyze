#include <stdio.h>

int main(){
  char line[100];
  int num;
  int count=0;
  while(1){
	fgets(line, sizeof(line), stdin);
	sscanf(line, "%d", &num);
	if(num==0)
	  break;
	++count;
	printf("Case %d: %d\n", count, num);
}
  return 0;
}
