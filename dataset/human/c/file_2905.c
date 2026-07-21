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
int main(void){
    int k, s;
    int x, y;
    int z;
    int ans=0;
    k = num();
    s = num();
    
    for(x=0; x<=k; x++){
        for(y=0; y<=k; y++){
            z = s-x-y;
            if(s-x-y <= k && z >= 0){
                ans++;
            }
        }
    }
    printf("%d\n", ans);
    
    return 0;
    
}
