#include<stdio.h>
int main()
{
    int i,n;
    char m;
    char a[100];

    while(scanf("%s",a)!=EOF)
    {

        n=0;
        for(i=50; i>=1; i--)
        {
            if('F'==a[i])
            {
                n=i+1;
                break;
            }
        }

        for(i=0; i<=n-2; i++)
            printf("%c",a[i]);
            printf("\n");
          for(i=0;i<=50;i++){
            a[i]='0';
          }
    }

    return 0;

}
