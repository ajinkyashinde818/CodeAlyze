#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(void){
    int N;
    scanf("%d",&N);
    int D,X,counter = 0;
    scanf("%d %d",&D,&X);
    int i,a[N];
    for(i=0;i<N;i++){
        counter ++;
        scanf("%d",&a[i]);
        counter += (D-1)/a[i];
    }
    counter += X;
    printf("%d\n",counter);
    
    return 0;
}
