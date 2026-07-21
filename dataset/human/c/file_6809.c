#include <stdio.h>
#include <stdlib.h>
int num(){
    char s[11];
    int i, n;
    for(i=0; i<sizeof(s); i++){
        s[i] = getchar();
        if(s[i] == ' ' || s[i] == '\n'){
            s[i] = '\0';
            break;
        }
    }
    sscanf(s, "%d", &n);
    return n;
}
int asc(const void *a, const void *b) {
    return *(int *)b - *(int *)a;
}
int main(void){
    int n, i, j=1;
    int a[300001];
    long ans=0;
    
    n = num();
    for(i=0; i<n*3; i++){
        a[i] = num();
    }
    
    qsort(a, n*3, sizeof(int), asc);
    
    for(i=0; i<n; i++){
        ans += a[j];
        j+=2;
    }
    
    printf("%ld\n", ans);
    
    return 0;
}
