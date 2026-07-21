#include <stdio.h>

int main()
{
        int friend;
        int height[100000];
        int min;
        int i;
        int count=0;

        scanf("%d %d",&friend,&min);

        for(i=0; i<friend; i++)
        {
                scanf("%d",&height[i]);
                if(height[i]>=min) {count++;}
        }
        printf("%d\n",count);

        return 0;

}
