#include <stdio.h>

int main() {

    int n,rj,ri,max,tmp,minv;
    int t[200001]={};
    int i,j;

    scanf("%d",&n);

    for(i = 0; i < n; i++){
        scanf("%d",&t[i]);
    }

    max = t[1] - t[0];

    // for(j = 1; j < n; j++){
    //     for(i = 0; i < j; i++){
    //         tmp = t[j] - t[i];
    //         if(tmp > max){
    //             max = tmp;
    //         }
    //     }
    // }

    minv = t[0];

    for(j = 1; j < n; j++){
        tmp = t[j] - minv;
        if (tmp > max) {
            max = tmp;
        }
        if (minv > t[j]) {
            minv = t[j];
        }

    }

    printf("%d\n",max);

    return 0;
}
