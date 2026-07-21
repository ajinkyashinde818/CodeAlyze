#include <stdio.h>
#include <stdlib.h>
int main(void){
    int n,i;
    scanf("%d",&n);
    int *p;
    p=malloc(n*sizeof(int));
    for(i=0;i<n;i++){
        scanf("%d",&p[i]);
    }
    int flag=1;
    for(i=0;i<n;i++){
        flag=p[flag-1];
        if(flag==2){
            printf("%d\n",i+1);
            return 0;
        }
    }
    printf("-1\n");
    return 0;
}
