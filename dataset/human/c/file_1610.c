#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	int ans=0,flag=0,first=0,last=99999;
	char s[100001];
	scanf("%s", s);
/*回文の先頭と末尾が同じならその2つは無視し除外できる。
sはkeepしfirstとlastの位置で何とかする。*/
	last = strlen(s)-1;
	while (flag == 0) {
		if (s[first] != s[last] && s[first] != 'x' && s[last] != 'x')flag++;
		else if (s[first] == s[last]) { first++; last--; }
		else if (s[first] == 'x' && s[last] != 'x') { first++; ans++; }
		else if (s[first] != 'x' && s[last] == 'x') { last--; ans++; }
		
		if (first >= last) { printf("%d", ans); return 0; }
	}
	printf("-1");
}
