#include <stdio.h>
int main(int argc, char const *argv[])
{
	int n;
	scanf("%d",&n);

	char str[n];
	scanf("%s",str);

	int a;
	scanf("%d",&a);

	for (int i = 0; i < n; ++i)
	{
		if (str[i]==str[a-1])
		{
			/* code */
		}else{
			str[i]='*';
		}
	}
	printf("%s\n", str);
	return 0;
}
