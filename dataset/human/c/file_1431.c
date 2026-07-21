#include<stdio.h>
#include<string.h>
int main(){
	char s[1000];
	int flag=0;
	scanf("%s",&s);
	for(int i=0;i<strlen(s);i++){
		if(s[i]=='9'){
			flag=1;
			printf("Yes\n");
			break;
		}
	}
	if(!flag) printf("No\n");
	return 0;
}
