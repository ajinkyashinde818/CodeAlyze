#include "stdio.h"
#include "string.h"

void sort_up(char* str)
{
	int i, j;
	char temp;
	int len = strlen(str);

	for(i=0;i<len+1;i++){
		for(j=0;j<len+1-i;j++){
			if(str[j]<str[j+1]) {
				temp = str[j];
				str[j] = str[j+1];
				str[j+1] = temp;
			}
		}
	}
}

void sort_down(char* str)
{
	int i, j;
	char temp;
	int len = strlen(str);

	for(i=0;i<len-1;i++){
		for(j=0;j<len-1-i;j++){
			if(str[j]>str[j+1]) {
				temp = str[j];
				str[j] = str[j+1];
				str[j+1] = temp;
			}
		}
	}
}


int main(void){
	char str1[100];
	char str2[100];
	int i;

	memset(str1, NULL, 100);
	memset(str2, NULL, 100);

	scanf("%s%s", str1, str2);

	sort_down(str1);
	sort_up(str2);

	for(i=0;i<100;i++){
		if(str1[i]<str2[i]){
			printf("Yes\n");
			return 0;
		}
		if(str1[i]>str2[i]){
			printf("No\n");
			return 0;
		}
	}

	printf("No\n");
	return 0;
}
