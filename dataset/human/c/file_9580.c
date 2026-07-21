#include<stdio.h>
int main()
{
    int i,j,cnt=0,cmt=0,sum=0;
    int n;
    scanf("%d",&n);
    int ar[n];
    int a,b,c;
    scanf("%d %d",&a,&b);
    for(i=0; i<n; i++)
    {
        scanf("%d",&ar[i]);
    }
    for(i=0; i<n; i++)
    {
            for(j=1; j<=a; j++)
            {
                if(ar[i]*j+1<=a){
                   cmt++;
                }
                else{
                    cnt++;
                    break;
                }


            }

        }
     printf("%d\n",cnt+cmt+b+n-cnt);
    return 0;
}
