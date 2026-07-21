#include <stdio.h>
#include <string.h>

int main(void){
	int i,ptr,cont,ans=0;
	char s[100001];
	char t[4][7]={"dream","dreamer","erase","eraser"};
	int len[4]={5,7,5,6};

	scanf("%s",s);

	ptr=strlen(s);

	while(ans==0){
		cont=1;
		for(i=0;i<4 && cont==1;i++){
			if(ptr-len[i]>=0){
				if(strncmp(s+ptr-len[i],t[i],len[i])==0){
					ptr-=len[i];
					if(ptr==0){
						ans=1;
					}
					cont=0;
				}
			}
		}
		if(cont==1){
			ans=-1;
		}
	}

	if(ans==1){
		printf("YES");
	}else if(ans==-1){
		printf("NO");
	}

	return 0;

}
