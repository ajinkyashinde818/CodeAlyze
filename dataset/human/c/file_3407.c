#include<stdio.h>
#include<string.h>
#define FOR(i,a,b) for(int i=a;i<b;i++)
int main(){
	char s[100002];
	char *tbl[] = {"dream","dreamer","erase","eraser"};
	int Len[] = {5,7,5,6};
	int len;

	scanf("%s",s);
	len = strlen(s);

	while(len > 0){
		FOR(i,0,4){
			if(strcmp(tbl[i],&s[len - Len[i]]) == 0){
				s[len - Len[i]] = '\0';
				len -= Len[i];
				break;
			}
			if(i == 3){
				printf("NO\n");
				return 0;
			}
		}
	}
	printf("YES\n");
}
