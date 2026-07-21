#include <stdio.h>
int main(int argc, char const *argv[]){
	int i;
	char s[4],c[3]={1,1,1};
	scanf("%s",s);
	for(i=0;i<3;i++){
		if(s[i]-'a'<0||s[i]-'a'>2)
			break;
		if(c[s[i]-'a']==0)
			break;
		c[s[i]-'a']=0;
	}
	if(i==3)
		printf("Yes\n");
	else
		printf("No\n");

	return 0;
}
