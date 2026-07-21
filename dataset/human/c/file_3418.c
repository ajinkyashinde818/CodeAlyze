#include <stdio.h>
#include <string.h>
int main(void){
	char de[4][10]={"dream","dreamer","erase","eraser"};
	char s[100001];
	int t=0,f=1;
	scanf("%s",s);
	while(strlen(s)-t>=5){
		if(strncmp(s+t,de[1],7)==0){
			if(strncmp(s+t+5,de[2],5)!=0){
				t+=7;
			}
			else{
				t+=5;
			}
		}
		else if(strncmp(s+t,de[0],5)==0){
			t+=5;
		}
		else if(strncmp(s+t,de[3],6)==0){
			t+=6;
		}
		else if(strncmp(s+t,de[2],5)==0){
			t+=5;
		}
		else{
			f=0;
			break;
		}
	}
	if(strlen(s)-t!=0){
		f=0;
	}
	if(f){
		puts("YES");
	}
	else{
		puts("NO");
	}
	return 0;
}
