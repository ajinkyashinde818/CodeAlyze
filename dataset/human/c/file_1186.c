#include <stdio.h>
#include <string.h>
int sorts(char*,int);
int sortt(char*,int);
int main() {
	char s[101],t[101];
	int sl,tl,count,check = 0;
	scanf("%s",s);
	scanf("%s",t);
	sl = strlen(s);
	tl = strlen(t);
	sorts(s,sl);
	sortt(t,tl);
	if(sl < tl) count = sl;
	else count = tl;
	for(int i = 0;i < count;i++) {
		if(s[i] < t[i]) {
			check = 1;
			break;
		}
		if(s[i] > t[i]) {
			check = 2;
			break;
		}
	}
	if(check == 1) printf("Yes\n");
	if(check == 2) printf("No\n");
	if(check == 0) {
		if(sl < tl) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}

int sorts(char * s,int sl) {
	char tmp;
	for(int j = sl - 1;j > 0;j--) {
		for(int k = 0;k < j;k++) {
			if(s[k] > s[k+1]) {
				tmp = s[k];
				s[k] = s[k+1];
				s[k+1] = tmp;
			}
		}
	}
	return 0;
}

int sortt(char * s,int sl) {
	char tmp;
	for(int j = sl - 1;j > 0;j--) {
		for(int k = 0;k < j;k++) {
			if(s[k] < s[k+1]) {
				tmp = s[k];
				s[k] = s[k+1];
				s[k+1] = tmp;
			}
		}
	}
	return 0;
}
