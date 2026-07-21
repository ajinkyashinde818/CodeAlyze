#include <stdio.h>
int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        int num,temp,j,i,d,x,a[110],sum=0;
        scanf("%d%d",&d,&x);
        for(i = 0;i < n; i++)
        {
            scanf("%d",&a[i]);
        }
        for(i = 0;i < n;i++)
        {
            j=2;
            num=1;
            temp=a[i];
            while(a[i]+1<=d)
            {
                num++;
                a[i]=j*temp;
                j++;


            }
            sum += num;

        }
        printf("%d\n",sum+x);



    }
}
