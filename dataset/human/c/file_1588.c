#include <stdio.h>
#include <string.h>
#define N 100001

char s[N];

int main() 
{
	int i, j, ti, tj, ans = 0, x, y;
	
	scanf("%s", s + 1);
	i = 0, j = strlen(s + 1) + 1;
	while(i < j){
		for(ti = i + 1; ti < j && s[ti] == 'x'; ti++);
		if(ti == j) break;
		for(tj = j - 1; s[tj] == 'x'; tj--);
		if(s[ti] != s[tj]){
			puts("-1");
			return 0;
		}
		x = ti - i, y = j - tj;
		if(y > x) ans += y - x;
		else ans += x - y;
		i = ti, j = tj;
	}
	printf("%d\n", ans);
			
	return 0;
}
