#include<stdio.h>

int main()
{
    int n,d,x,a[200],y,z,sum=0;

    scanf(" %d %d %d",&n,&d,&x);
    for(y=0;y<n;y++)
        scanf(" %d",&a[y]);

    for(y=0;y<n;y++){
        for(z=1;z<=d;z+=a[y]){
            sum++;
        }
    }

    printf("%d\n",sum+x);



    return 0;
}
