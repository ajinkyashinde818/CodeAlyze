#include <stdio.h>
#include <string.h>
//using ll = long long;

int main(){
    int n, k, i;
    char s[1000000];
    scanf("%d",&n);
    scanf("%s",s);
    scanf("%d",&k);
    for (i=0;i<n;i++){

        if(s[i] != s[k-1]){
            s[i] = '*';
        }
    }
    printf("%s\n",s);
    return 0;
}
