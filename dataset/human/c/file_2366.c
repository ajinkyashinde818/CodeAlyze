#include<stdio.h>
#include<math.h>
#include<string.h>
int main ()
{
	int i,j,k;
	char a[4];
	k=0;
	for(i=0;i<3;i++)
		scanf("%c",&a[i]);
	for(i=0;i<3;i++)
		for(j=i+1;j<3;j++)
		{
			if(a[i]==a[j])
			{
				k++;	
			}	
		}
	if(k!=0)
		printf("No\n");
	else
		printf("Yes\n");
	return 0;
}
