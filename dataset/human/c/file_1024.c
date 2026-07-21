#include<stdio.h>

int main()
{	
	int n, i, j;
	while((scanf("%d", &n)!=EOF) && n){
		int key[100] = {};
		char s[100] = {};
		char ans[100] = {};
		
		for(i = 0; i < n; i++)		scanf("%d", &key[i]);
		for(i = n; i < 100; i++)	key[i] = key[i%n];
		
		scanf("%s", s);
		
		for(i = 0; i < 100; i++)	if(s[i]!='\0')	ans[i] = s[i];
		
		for(i = 0; i < 100; i++)
		{
			if(s[i] == '\0')	break;
			for(j = 0; j < key[i]; j++)
			{
				if(ans[i] == 'a')	ans[i] = 'Z';
				else if(ans[i] == 'A')	ans[i] = 'z';
				else	ans[i]--;
			}
		}
		printf("%s\n", ans);
	}
	return 0;
}
