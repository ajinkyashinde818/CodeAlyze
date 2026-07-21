#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define N 100000

int main(void){
    char s[N], c;
    int len=0, l, r;
    int ret = 0;

    while(isalnum(c = getchar()))
        s[len++] = c;

    l = 0; r = len -1;
    while(l <= r){
        if(s[l] == s[r]){
            l++; r--;
        }
        else{
            if(s[l] == 'x'){
                l++;
                ret++;
            }
            else if(s[r] == 'x'){
                r--;
                ret++;
            }
            else{
                ret = -1;
                break;
            }
        }
    }
    
    printf("%d\n", ret);

    return 0;
}
