#include<stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    int a[n], b[n], c[n-1];
    for(int i=0; i<n; i++){
        scanf("%d", &a[i]);
        a[i]--;
    }
    for(int i=0; i<n; i++){
        scanf("%d", &b[i]);
    }
    for(int i=0; i<n-1; i++){
        scanf("%d", &c[i]);
    }
    int sum = b[a[0]];
    int p = a[0];
    for(int i=1; i<n; i++){    
        sum += b[a[i]];
        if(p + 1 == a[i]){
            sum += c[p];
        }
        p = a[i];
    }
    printf("%d", sum);

    return 0;
}
