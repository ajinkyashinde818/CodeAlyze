#include <stdio.h>
int main(){
	char a[3];
	int x=0,y=0,z=0;
	scanf("%s",&a);
	for (int i = 0; i < 3; ++i)
	{
		if (a[i]=='a')
		{
			x=x+1;
		}else if (a[i]=='b')
		{
			y=y+1;
		}else if (a[i]=='c')
		{
			z=z+1;
		}
	}
	if (x==1&&y==1&&z==1)
	{
		printf("Yes\n");
	}else{
		printf("No\n");
	}
}
