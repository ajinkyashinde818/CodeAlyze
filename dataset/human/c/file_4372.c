#include <stdio.h>
int main(void)
{
    int N,dice1,dice2;
    int counter=0;
    scanf("%d",&N);
    for(int i=0;i<N;i++)
    {
        scanf("%d %d",&dice1,&dice2);
        if(dice1==dice2)
            counter++;
        else
            counter=0;
        if(counter==3)
        {
            printf("Yes\n");
            break;
        }
        else if(i==N-1)
        {
            printf("No\n");
        }   
    }
    return 0;
}
