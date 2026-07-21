#include<stdio.h>

#define MAX 200000

int main(){
    int R, n, i, maxv, minv;

    scanf("%d", &n);

    for(i=0; i<n; i++){

        scanf("%d", &R);

        if(i==0){
            maxv=-2000000000;
            minv=R;
        }else{
            if(maxv < (R-minv)) maxv=R-minv;
            if(minv > R) minv=R;
        }
    }

    printf("%d\n", maxv);

    return 0;
}
