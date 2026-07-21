#include <stdio.h>
#include <ctype.h>

int a2i(char a) {
	if(islower(a))return a-'a';
	if(isupper(a))return a-'A'+26;
	return 0;
}

char i2a(int i) {
	if(i<26)return i+'a';
	else return i-26+'A';
}

int main(void) {
	int n,i;
	int key[100];
	char s[200];
	while(scanf("%d",&n)==1 && n>0) {
		for(i=0;i<n;i++)scanf("%d",&key[i]);
		scanf("%s",s);
		for(i=0;s[i];i++) {
			putchar(i2a((a2i(s[i])-key[i%n]+52)%52));
		}
		putchar('\n');
	}
	return 0;
}
