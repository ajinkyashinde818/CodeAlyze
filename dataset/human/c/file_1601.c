#include <stdio.h>
#include <stdlib.h>
#define max_size (int)(1e5 + 1)

int main(){
	int i, j, N, ans = 0;
	char *s = (char *)malloc(sizeof(char) * max_size);
	scanf("%s", s);
	for(i = 0; s[i] != '\0'; i++){}
	N = i;
	for(i = 0, j = N - 1; j - i > 0; ){
		if(s[i] == s[j]){
			i++;
			j--;
		}
		else if(s[i] == 'x'){
			ans++;
			i++;
		}
		else if(s[j] == 'x'){
			ans++;
			j--;
		}
		else{
			printf("-1\n");
			return 0;
		}
	}
	printf("%d\n", ans);
	return 0;
}
