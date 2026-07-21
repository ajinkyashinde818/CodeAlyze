#include <stdio.h>
#include <string.h>
int main()
{
	 int n,m,i,j,k,s,l;
	 char a[150];
	 char b[150];
	 char t;
	 
	while(scanf("%s",a)!=EOF)
	{
		scanf("%s",b);
		l=strlen(a);
		for(i=0;i<=l-2;i++)
		  {
		  	 for(j=l-1;j>i;j--)
		  	  {
		  	  	 if(a[j]<a[j-1])
		  	  	 {
		  	  	 	 t=a[j];
		  	  	 	 a[j]=a[j-1];
		  	  	 	 a[j-1]=t;
		  	  	 }
		  	  }
		  }
		  l=strlen(b);
		  for(i=0;i<=l-2;i++)
		  {
		  	 for(j=l-1;j>i;j--)
		  	  {
		  	  	 if(b[j]>b[j-1])
		  	  	 {
		  	  	 	 t=b[j];
		  	  	 	 b[j]=b[j-1];
		  	  	 	 b[j-1]=t;
		  	  	 }
		  	  }
		  }
		  if(strcmp(a,b)<0)
		  printf("Yes\n");
		  else
		  printf("No\n");
		  memset(a,'\0',sizeof(a));
		  memset(a,'\0',sizeof(b));
	}
}
