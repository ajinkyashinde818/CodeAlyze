#include <stdio.h>

int N,a[100000][2];

main(){
    int i,j;
    scanf("%d",&N);
    for(i=0;i<N;i++)
        scanf("%d",&a[i][0]);

    i=j=0;
    while(1){
        if(a[i][1]++){
            puts("-1");
            break;
        }
        if(a[1][1]){
            printf("%d\n",j);
            break;
        }
        i=a[i][0]-1;
        j++;
    }
    return 0;
}
