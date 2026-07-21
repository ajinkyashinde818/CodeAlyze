#include<stdio.h>
#include<string.h>
int check(char s[])
{
	int i,l;
	l=strlen(s);
	
	for (i=0;i<=l/2+1;i++)
	{
		if (s[i]!=s[l-1-i])
			return 0;
	}
	
	return 1;

}
int main()
{
	char flag,s1[100001],s2[100001];
	int i,j,l,ans;
	scanf("%s",s1);
	j=0;
	l=strlen(s1);
	for (i=0;i<l;i++)
	{

		if (s1[i]!='x')
		{
			s2[j]=s1[i];
			j++;
		}
	}
	s2[j]='\0';
	flag=check(s2);
	if (flag)
	{
		ans=0;
		i=0;
		j=l-1;
		while (i<j)
		{
			if (s1[i]==s1[j])
			{
				i++;
				j--;
			}
			else 
			{
				if (s1[i]=='x')
				{
				    i++;
					ans++;
				}
			    else if (s1[j]=='x')
				{
				    j--;
					ans++;
				}
			}

		}
		printf("%d\n",ans);
		
	}
	else printf("-1\n");
	return 0;


}
