#include<stdio.h>
int main(){
    int l[3];
    for (int i = 0; i < 4; i++)
    {
        scanf("%d",&l[i]);
    }
    int a=l[0]*l[1];
    int b=l[2]*l[3];
    if (a>b)
        printf("%d",a);
    else
        printf("%d",b);
    
    return 0;
}
