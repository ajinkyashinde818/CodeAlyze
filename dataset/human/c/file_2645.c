#include <stdio.h>

// first type, to use switch-case. ?include "abc"
// second type, to use ascii number. ?(sum(a,b,c)==sum(str)) 
int main(void){
	char str[3];
	int c = 6;
	scanf("%s",&str);

	int sum = 'a'+'b'+'c';

	for(int i=0;i<sizeof(str);i++){
		switch(str[i]){
			case 'a':
				c -= 1;
				break;
			case 'b':
				c -= 2;
				break;
			case 'c':
				c -= 3;
		}
		sum -= str[i];
	}


	if(!sum)
		printf("%s\n","Yes");
	else
		printf("%s\n","No");

	return 0;
}
