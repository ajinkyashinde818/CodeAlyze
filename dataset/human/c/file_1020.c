#include<stdio.h>
#define MAX 100
#define KEY 52

int n;
int k[KEY];
char s[MAX];
char t;

int main(){
	int i,j;
	
	while(1){

		s[0] = '\0';
		scanf("%d",&n);

		if(n == 0) break;

		for(i = 0; i < n; i++){
			scanf("%d",&k[i]);
		}

		scanf("%s",s);

		for(i = j = 0; s[i] != '\0'; i++){
			char t = s[i] - k[j];
		
			if(t < 'A' && ('A' <=s[i] && s[i] <= 'Z')) {
         t += 58;
				 if(t < 'a') t -= 6;
			}
			if(t < 'a' && ('a' <= s[i] && s[i] <= 'z')){
         t -= 6;
				 if(t < 'A') t += 58;
			}
				
			j++;
			printf("%c",t);
			if(j == n)j = 0;
 
	}
		printf("\n");
	}
	return 0;
}
