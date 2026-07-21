#include <stdio.h>

int Max(int x,int y);
int Min(int x,int y);

int main(){
    int N;
    scanf("%d",&N);

    int min;
    int up_max;
    int up;
    int x;

    scanf("%d",&min);

    scanf("%d",&x);
    up_max=x-min;
    min=Min(min,x);

    for(int i=0;i<N-2;i++){
        scanf("%d",&x);
        up=x-min;
        up_max=Max(up_max,up);
        min=Min(min,x);
    }

    printf("%d\n",up_max);
}

int Max(int x,int y){
    if(x>=y)
        return x;
    else
        return y;
}
int Min(int x,int y){
    if(x<=y)
        return x;
    else
        return y;
}
