#include<stdio.h>
int main(void)
{
    long int n,a[100000],s=0,i;
    scanf("%ld",&n);
    for(i=1;i<=n;i++)
        scanf("%ld",&a[i]);
    i=1;
    while(s<=n){
        s++;
        if(a[i]==2)
            break;
        i=a[i];
    }
    if(s>n)
        s=-1;
    printf("%ld\n",s);
    return 0;
}
