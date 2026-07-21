#include <stdio.h>

int main(){
    int n, d, x, a[100];
    int i, j, cnt=0;

    scanf("%d %d %d", &n, &d, &x);

    for(i=0; i<n; i++)
        scanf("%d", &a[i]);
    
    for(i=0; i<n; i++){
        j=0;
        while(j*a[i]+1 <= d){
            cnt++;
            j++;
        }
    }

    printf("%d\n", x+cnt);

    return 0;
}
