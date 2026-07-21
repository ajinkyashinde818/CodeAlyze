#include <stdio.h>
int main()
{
    int a;
    scanf("%d",&a);
    int b[a],c[a],d[a];
    for(int i=0;i<a;i++){
        scanf("%d",&b[i]);
    }
    for(int i=0;i<a;i++){
        scanf("%d",&c[i]);
    }
    for(int i=0;i<a-1;i++){
        scanf("%d",&d[i]);
    }
    int e=0;
    for(int i=0;i<a;i++){
        e+=c[i];
    }
    for (int i = 0; i < a-1; i++)
    {
        if(b[i+1]==b[i]+1){
            e+=d[b[i]-1];
        }
    }
    printf("%d\n",e);
    return 0;
}
