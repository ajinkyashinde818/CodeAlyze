#include<stdio.h>
int main(void)
{
    int n,d,x,a[101]={0},i,j,c=0;
    scanf("%d%d%d",&n,&d,&x);
    for(i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(i=1;i<=n;i++){
        j=0;
        while((1+(j*a[i]))<=d){
            c++;
            j++;
        }
    }
    c+=x;
    printf("%d\n",c);
    return 0;
}
