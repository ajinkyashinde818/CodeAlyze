#include<cstdio>
#include<string.h>
using namespace std;
int main()
{
    int n,k,r,g,b,i,j;
    while(scanf("%d %d %d %d",&r,&g,&b,&n)==4)
    {
        int sum=0;
        for(i=0; i*r<=n; i++)
            for(j=0; j*g+i*r<=n; j++)
            {
                int num=n-j*g-i*r;
                if(num%b==0)
                    sum++;
            }
        printf("%d\n",sum);
    }

    return 0;
}
