#include <stdio.h>
int main()
{   int t,d=1,x=0;

    scanf("%d", &t);
    int a[t*2];
    for (int i = 0; i < t*2; i++)
        {
            scanf("%d", &a[i]);
        }
      for (int i = 0; i < t*2; i+=2)
    {
        if(a[i]==a[i+1])
        {
           x++;
           if(x>=3)
           {
               break;
           }
           continue;

        }
        else
        {
            x=0;
        }
    }
    if(x>=3)
        printf("Yes");
    else
        printf("No");

    return 0;
}
