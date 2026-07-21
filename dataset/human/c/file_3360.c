#include <stdio.h>
#include <string.h>

int main(void)
{
	char S[100000],T[10000],*p;
	int i,judge=0,length;
	scanf("%s",&S);
	length=strlen(S);
	for(i=0;i<length;i++){
		if(S[i]=='d'&&S[i+1]=='r'&&S[i+2]=='e'&&S[i+3]=='a'&&S[i+4]=='m'){
			if(S[i+5]=='e'&&S[i+6]=='r'){
				i=i+6; judge=1;
			}
			else{
				i=i+4; judge=0;
			}

		}else if(S[i]=='e'&&S[i+1]=='r'&&S[i+2]=='a'&&S[i+3]=='s'&&S[i+4]=='e'){
			if(S[i+5]=='r'){
				i=i+5; judge=1;
			}
			else{
				i=i+4; judge=0;
			}
		}else{
			if(judge==1){
				i-=3; judge=0;
			}else{
			break;
			}
		}
	}

	printf("%s\n",i>=length||judge==1 ? "YES" : "NO" );
	return 0;
}
