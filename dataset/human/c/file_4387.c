#include <stdio.h>

int main()
{

    int n;
    scanf("%d", &n);
    int i;
    int b, c;
    int N[110];
    for (i = 0; i < n; i++)
    {
        scanf("%d %d", &b,&c);
        if(b==c){
            N[i] = 1;
        }else
            N[i] = 0;
    }

    int Sum = 0;
    for (i = 0; i < n; i++)
    {

        if (N[i] == 1)
        {
            Sum++;
            if (Sum>=3){
                break;
            }
        }
        else
            Sum=0;
    
    }

    if (3<=Sum)
    {
        printf("Yes");
    }
    else
    {
        printf("No");
    }

    printf("\n");
}
