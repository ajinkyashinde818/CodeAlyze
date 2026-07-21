#include <stdio.h>

#define SIZE 10000

int main()
{
    int data[SIZE];
    int a=1,i=0;

    while(a != 0){
        scanf("%d",&a);
        data[i] = a;
        i++;
    }
    for(a=0;a<i-1;a++){
        printf("Case %d: %d\n",a+1,data[a]);
    }

    return 0;
}
