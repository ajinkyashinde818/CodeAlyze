#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
	char s[100001], c;
	s[0]=0;
	int p=0;
	while((c=getchar())!=10) s[++p]=c;
	while(p>0){
		if(s[p]=='m'){
			if(s[--p]=='a' && s[--p]=='e' && s[--p]=='r' && s[--p]=='d'){
				p--;
			}else break;
		}else if(s[p]=='e'){
			if(s[--p]=='s' && s[--p]=='a' && s[--p]=='r' && s[--p]=='e'){
				p--;
			}else break;
		}else if(s[p]=='r'){
			if(s[--p]=='e'){
				p--;
				if(s[p]=='m'){
					if(s[--p]=='a' && s[--p]=='e' && s[--p]=='r' && s[--p]=='d'){
						p--;
					}else break;
				}else if(s[p]=='s'){
					if(s[--p]=='a' && s[--p]=='r' && s[--p]=='e'){
						p--;
					}else break;
				}else break;
			}else break;
		}else break;
	}
	puts(p==0?"YES":"NO");
}
