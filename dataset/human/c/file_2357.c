#include <stdio.h>
int main(void){
	int i, a, b, c;
	char s[4];

	scanf("%s", s);
	a = b = c = 0;
	for(i=0; i<3; i++){
		if(s[i] == 'a') a++;
		if(s[i] == 'b') b++;
		if(s[i] == 'c') c++;
	}

	if((a==1)&&(b==1)&&(c==1))
		printf("Yes\n");
	else
		printf("No\n");

	return 0;
}
