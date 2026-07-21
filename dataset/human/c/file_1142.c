#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

int main(void){

    char s[101], t[101];

    scanf("%s%s", s, t);

    int lens = strlen(s), lent = strlen(t);

    for(int i = 0; i < lens; i++){
        for(int j = i+1; j < lens; j++){
            char k[2];
            if(s[i] > s[j]){
                k[0] = s[i];
                s[i] = s[j];
                s[j] = k[0];
            }
        }
    }

    for(int i = 0; i < lent; i++){
        for(int j = i+1; j < lent; j++){
            char l[2];
            if(t[i] < t[j]){
                l[0] = t[i];
                t[i] = t[j];
                t[j] = l[0];
            }
        }
    }

    if(strcmp(s, t) < 0){
        printf("Yes\n");
    }else{
        printf("No\n");
    }

    return 0;
}
