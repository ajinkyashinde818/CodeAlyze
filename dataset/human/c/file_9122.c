#include <stdio.h>
#include <stdlib.h>
int main(void) {
int N,K;
int count =0;
scanf("%d %d",&N,&K);
int arr[N];
for (int i=0;i<N;i++){
    scanf("%d",&arr[i]);
    if (arr[i]>=K) count++;
}
printf("%d",count);
 return EXIT_SUCCESS;
}
