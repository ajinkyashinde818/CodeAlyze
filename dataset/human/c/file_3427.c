#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max_size (int)(1e5 + 1)

int main(){
	int N, i;
	char *S = (char *)malloc(sizeof(char) * max_size);
	scanf("%s", S);
	for(i = 0; S[i] != '\0'; i++){}
	N = i;
	for(i = N - 1; i >= 0; ){
		if(i >= 6){
			if(strncmp(&S[i - 4], "dream", 5) == 0){
				i -= 5;
			}
			else if(strncmp(&S[i - 6], "dreamer", 7) == 0){
				i -= 7;
			}
			else if(strncmp(&S[i - 4], "erase", 5) == 0){
				i -= 5;
			}
			else if(strncmp(&S[i - 5], "eraser", 6) == 0){
				i -= 6;
			}
			else{
				printf("NO\n");
				return 0;
			}
		}
		else if(i == 5){
			if(strncmp(&S[i - 5], "eraser", 6) == 0){
				i -= 6;
			}
			else{
				printf("NO\n");
				return 0;
			}
		}
		else if(i == 4){
			if(strncmp(&S[i - 4], "dream", 5) == 0){
				i -= 5;
			}
			else if(strncmp(&S[i - 4], "erase", 5) == 0){
				i -= 5;
			}
			else{
				printf("NO\n");
				return 0;
			}
		}
		else{
			printf("NO\n");
			return 0;
		}
	}
	printf("YES\n");
	return 0;
}
