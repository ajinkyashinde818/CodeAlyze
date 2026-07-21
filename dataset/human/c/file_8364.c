#include <stdio.h>
#include <stdlib.h>

int main(){
	int n, k;
	char *s;
	
	scanf("%d", &n);
	s = malloc(sizeof(char) * (long)n);
	scanf("%s%d", s, &k);
	char a = s[k - 1];
	for(int i = 0; i < n; ++i){
		printf("%c", a == s[i] ? a : '*');
	}
	printf("\n");
	free(s);
	return 0;
}
