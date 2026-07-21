#include <stdio.h>
#include <stdlib.h>

int main(void) {
	char s[4];
	scanf("%s",s);
	int i,frag[3]={};
	for(i=0;i<3;i++){
		frag[s[i]-'a']++;
	}
	for(i=0;i<3;i++){
		if(frag[i]!=1){
			printf("No\n");
			break;
		}
	}
	if(i==3){
		printf("Yes\n");
	}
	return EXIT_SUCCESS;
}
