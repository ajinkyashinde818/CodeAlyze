#include <stdio.h>
#include <string.h>

int main(){
	char s,t[5];
	t[4] = '\0';
	int flag = 0;
	int flag2 = 0;//dream**=1, erase*2, dreamer3
	int ret,ret2;
	while(1){
		ret = scanf("%c",&s);
		if(ret == EOF || s == '\n') break;
		if(s == 'd'){
			ret2 = scanf("%c%c%c%c",&t[0],&t[1],&t[2],&t[3]);
			if(ret2 == EOF || strcmp(t,"ream") != 0) flag = 1;
			flag2 = 1;
		}else if(s == 'e'){
			if(flag2 == 0 || flag2 == 3 || flag2 == 2){
				ret2 = scanf("%c%c%c%c",&t[0],&t[1],&t[2],&t[3]);
				if(ret2 == EOF || strcmp(t,"rase") != 0) flag = 1;
				flag2 = 2;
			}else if(flag2 == 1){//(~dream)e
				ret2 = scanf("%c",&t[0]);
				if(ret2 == EOF || t[0] != 'r') flag = 1;
				else flag2 = 3;// -> (~dreamer)(~) or (~dreamer)ase(r)(~)
			}else flag = 1;
		}else if(flag2 == 2 && s == 'r') flag2 = 0;
		else if(flag2 == 3 && s == 'a'){
			ret2 = scanf("%c%c",&t[0],&t[1]);
			if(ret2 == EOF || t[0] != 's' || t[1] != 'e') flag = 1;
			else flag2 = 2;
		}
		else flag = 1;
		
		if(flag == 1) break;
	}
	
	if(flag == 0) printf("YES\n");
	else printf("NO\n");
	
	return 0;
}
