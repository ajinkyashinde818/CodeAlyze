#include<stdio.h>
int main(void)
{
char str[4];
scanf("%s",str);

int i,a,b,c;//a,b,cはそれぞれがあることを示す
a=b=c=0;
for(i=0;i<3;++i){//フラグ分岐
	if(str[i]=='a') a=1;
	if(str[i]=='b')	b=1;
	if(str[i]=='c')	c=1;
}

if(a==0||b==0||c==0) printf("No\n");
else printf("Yes\n");

return 0;
}
