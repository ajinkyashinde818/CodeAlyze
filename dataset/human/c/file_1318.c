#include<stdio.h>
#include<string.h>
int main()
{
    int n,t,o;
	int l[200008],r[200008];
	while(~scanf("%d%d",&n,&t))
	{
		o=0;
		memset(l,0,sizeof(l));
		memset(r,0,sizeof(r));
		int temp1,temp2;
		for(int i=0;i<t;i++)
		{
			scanf("%d%d",&temp1,&temp2);
			if(temp1>temp2)
               {
                   int x;
                   x=temp1;
                   temp1=temp2;
                   temp2=x;
               }
			if(temp1==1&&temp2!=n)
                l[temp2]++;
            else if(temp2==n&&temp1!=1)
                r[temp1]++;
		}

		for(int i=1;i<=n;i++)
		{
		    if(l[i]&&r[i])
            {
                o=1;
                break;
            }
		}
		if(o!=1) printf("IMPOSSIBLE\n");
		else printf("POSSIBLE\n");
	}
	return 0;
 }
