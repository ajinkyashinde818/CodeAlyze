#include <stdio.h>
#include <string.h>
int main(void){
	char s[100001];
	scanf("%s",s);
	for(long i=strlen(s);i>0;){
		if(strncmp(s+i-5,"dream",5)==0)	i-=5;
		else if(strncmp(s+i-7,"dreamer",7)==0) i-=7;
		else if(strncmp(s+i-5,"erase",5)==0) i-=5;
		else if(strncmp(s+i-6,"eraser",6)==0) i-=6;
		else{
			printf("NO");
			return 0;
		}
	}
	printf("YES");
	return 0;
}
