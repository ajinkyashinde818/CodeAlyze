#include <stdio.h>

int main()
{
    int n,d,x,res=0;
    scanf("%d", &n);
    scanf("%d %d", &d,&x);
    int a[n];
    for(int i=0;i<n;i++){
        scanf("%d", &a[i]);
    }
    for(int i=1;i<=d;i++){
        for(int j=0;j<n;j++){
            if(((i-1)%a[j])==0){
                res++;
            }
        }
    }
    printf("%d\n", res+x);
    return 0;
}
