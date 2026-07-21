#include <stdio.h>

int main(void){
	int i;
	char s[3];
	 for(i=0;i<3;i++){
		scanf("%c",&s[i]);
        }
	if(s[0]=='a'||s[1]=='a'||s[2]=='a'){
		if(s[0]=='b'||s[1]=='b'||s[2]=='b'){
			if(s[0]=='c'||s[1]=='c'||s[2]=='c') {
				printf("Yes\n");
			}else  printf("No\n");
		}else printf("No\n");
	}else printf("No\n");
	return 0;
}
