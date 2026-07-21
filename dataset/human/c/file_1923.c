// B - Buffet
#include <stdio.h>

int main(void){
    int a[20], b[20], c[20];
    int n, i, sum=0;
    scanf("%d", &n);
    for(i=0; i<n; i++){scanf("%d", &a[i]);}
    for(i=0; i<n; i++){scanf("%d", &b[i]);}
    for(i=0; i<n-1; i++){scanf("%d", &c[i]);}

    for(i=0; i<n; i++){
        sum+=b[a[i]-1];
        if(i>0 && a[i]==a[i-1]+1){sum+=c[a[i-1]-1];}
    }
    printf("%d\n", sum);
    return 0;
}
