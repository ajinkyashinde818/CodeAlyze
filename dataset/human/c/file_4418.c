#include<stdio.h>
int main(void)
{
    int N,a[101]={0},b[101]={0},i,f=0;
    scanf("%d",&N);
    for(i=0;i<N;i++)
    {
        scanf("%d %d",&a[i],&b[i]);
        if(a[i]==b[i]){
            f++;
            if(f==3) {
                printf("Yes");
                return 0;
            }
        }
        else f=0;
    }
    printf("No");

    return 0;
}
