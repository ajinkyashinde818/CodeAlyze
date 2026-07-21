#include <stdio.h>
 
int main()
{
	char S[3];
	int check_char[3]={0,0,0};
	scanf("%s",&S);
	for(int i=0;i<3;i++){
		if(S[i]=='a') check_char[0]=1;
		if(S[i]=='b') check_char[1]=1;
		if(S[i]=='c') check_char[2]=1;
	}
	if(check_char[0]==0||check_char[1]==0||check_char[2]==0)printf("No\n");
	else printf("Yes\n");
	return 0;
}
