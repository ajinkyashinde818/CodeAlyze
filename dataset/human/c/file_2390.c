#include<stdio.h>
char s[4];
int main(){
	scanf("%s",s);
	int cnta=0,cntb=0,cntc=0;
	for(int i = 0; i < 3;i++){
		if (s[i]=='a') cnta++;
		if (s[i]=='b') cntb++;
		if (s[i]=='c') cntc++;
	}
	if(cnta == 1&& cntb==1&& cntc==1) puts("Yes");
	else puts("No");
}
