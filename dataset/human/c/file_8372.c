#include<stdio.h>
#include<string.h>
typedef long long int ll;
int main()
{

    int n,k,i;
    char a[15];
    scanf("%d",&n);
    getchar();
    for(i=0;i<n;i++)
        scanf("%c",&a[i]);
    scanf("%d",&k);
    for(i=0;i<n;i++)
    {
        if(a[k-1]==a[i])
            printf("%c",a[i]);
        else
            printf("*");
    }
	return 0;
}
