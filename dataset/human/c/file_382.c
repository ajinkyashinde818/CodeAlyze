#include<stdio.h>

int main()
{
    int N,R,I;
    scanf("%d %d",&N,&R);
    if(N<=100 && N>=1)
    {
        if(R<=4111 && R>=0)
        {
            if(N<=10)
            {
                I=R+100*(10-N);
                printf("%d",I);
            }
            else
                printf("%d",R);

        }
    }

        return 0;
}
