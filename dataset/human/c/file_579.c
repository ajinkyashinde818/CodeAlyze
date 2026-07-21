#include <stdio.h>
#include <string.h>


int main()
{
	int n,m,i,j,k,l,flag;
	char a[50][50],b[50][50];

	scanf("%d%d",&n,&m);

    for (i = 0; i < n; ++i)
    {
    	scanf("%s",a[i]);
    }
	for (i = 0; i < m; ++i)
    {
    	scanf("%s",b[i]);
    }
    

    for (k = 0; k+m-1 <= n ; ++k)
    {
    	for (l = 0; l+m-1 <= n; ++l)
        {
        	flag = 0;
		    for (i = 0; i < m ; ++i)
		    {
		    	for (j = 0; j < m; ++j)
		    	{
		    		if(a[k+i][l+j] != b[i][j]){
		    			flag = 1;
		                break;
		    		}
		    	}
		    	if(flag == 1){
	                break;
		    	}
		    }
		    if(flag == 0)
		    {
                printf("Yes\n");
                return 0;
		    }
		}
	}
	printf("No\n");
	return 0;
}
