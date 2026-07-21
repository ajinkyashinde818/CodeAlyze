#include<stdio.h>

int main(){
	char S[100000];
	scanf("%s",S);
	int i,frag = 0;
	for(i = 0; S[i] != '\0'; i++){
		if(S[i] == 'd' && S[i + 1] == 'r' && S[i + 2] == 'e' && S[i + 3] == 'a' && S[i + 4] == 'm'){
			if(S[i + 5] == 'e' && S[i + 6] == 'r'){
				if(S[i + 7] == 'a' && S[i + 8] == 's' && S[i + 9] == 'e'){
					i+=4;
				} else {
					i+=6;
				}
			} else {
				i += 4;
			}
		} else if(S[i] == 'e' && S[i + 1] == 'r' && S[i + 2] == 'a' && S[i + 3] == 's' && S[i + 4] == 'e'){
			if(S[i + 5] == 'r'){
				i += 5;
			} else {
				i += 4;
			}
		} else /*if(S[i] == '\0' || S[i + 1] == '\0' || S[i + 2] == '\0' || S[i + 3] == '\0' || S[i + 4] == '\0'){
			break;
		} else */{
			frag++;
			break;
		}
	}
	if(frag == 0){
		printf("YES");
	} else {
		printf("NO");
	}
	return 0;
}
