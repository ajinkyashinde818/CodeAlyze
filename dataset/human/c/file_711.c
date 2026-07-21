#include <stdio.h>

char line[100005];

int main(void){
	
	int n; scanf("%d %s", &n, line);
	int alpha[26] = {0, };
	for(int i=0; i<n; i++) alpha[line[i]-'a']++;
	
	long long int s = 1, r = 1000 * 1000 * 1000 + 7;
	for(int i=0; i<26; i++) s = s * (alpha[i]+1) % r;
	s--; if(s<0) s += r;
	
	printf("%lld", s);
	
	return 0;
}
