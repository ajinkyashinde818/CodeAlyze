#include<stdio.h>
#include<string.h>
void sort(char x[])
{
	int i,j,n;
	char t;

	n=strlen(x);
	for(i=0;i<n;i++)
		for(j=i+1;j<n;j++)
			if(x[i]>x[j]){
				t=x[i];
				x[i]=x[j];
				x[j]=t;
			}
}

void tros(char x[])
{
	int i,j,n;
	char t;

	n=strlen(x);
	for(i=0;i<n;i++)
		for(j=i+1;j<n;j++)
			if(x[i]<x[j]){
				t=x[i];
				x[i]=x[j];
				x[j]=t;
			}	
}

int main()
{
	char s[111],t[111];

	scanf("%s%s",s,t);

	sort(s);
	tros(t);
	printf("%s",(strcmp(s,t)<0)?"Yes":"No");
	return 0;
}
