#include<stdio.h>
int main()
{
	int i,a=0,b=0,c=0;
	char s[4];
	scanf("%s",s);
	for(i=0;i<3;i++){
	if(s[i]=='a') a++;
	if(s[i]=='b') b++;
	if(s[i]=='c') c++;}
	 if(a==b&&b==c&&c==1)
	 printf("Yes\n");
	 else printf("No\n");
	 return 0;


}
