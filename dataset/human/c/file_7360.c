#include<stdio.h>
#define MAX_LEN 10000

int main()
{
    int array[MAX_LEN];
    
    int len=0;
    while(true)
    {
        int num;
        scanf("%d",&num);
        if(num==0)break;
        len++;
        array[len-1]=num;
    }
    
    for(int i=0;i<len;i++)
    {
        printf("Case %d: %d\n",i+1,array[i]);
    }
    return 0;
}
