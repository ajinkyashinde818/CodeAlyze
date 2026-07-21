#include <stdio.h>

int main(void){
	int keys[100];
	int n,i;
	char s[101];

	while(scanf("%d",&n),n){
		for(i=0;i<n;i++){
			scanf("%d",&keys[i]);
		}
		scanf("%s",s);
		for(i=0;s[i];i++){
			if('a'<=s[i]&&s[i]<='z'){
				s[i]=s[i]-'a';
			}else if('A'<=s[i]&&s[i]<='Z'){
				s[i]=26+s[i]-'A';
			}
			s[i]=(52+s[i]-keys[i%n])%52;
			if(0<=s[i]&&s[i]<26){
				s[i]+='a';
			}else if(26<=s[i]&&s[i]<52){
				s[i]-=26;
				s[i]+='A';
			}
		}
		printf("%s\n",s);
	}
	return 0;
}
