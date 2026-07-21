#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<limits.h>

#define rep(i,begin,end) for(int i=begin; i<end; i++)
#define revrep(i,begin,end) for(int i=begin; i>end; i--)
#define lld long long int

int cmpAsc(const void* a, const void* b){
    char x = *(char*)a, y = *(char*)b;
    if(x > y){
        return 1;
    }
    if(x < y){
        return -1;
    }
    return 0;
}

int cmpDsc(const void* a, const void* b){
    char x = *(char*)a, y = *(char*)b;
    if(x < y){
        return 1;
    }
    if(x > y){
        return -1;
    }
    return 0;
}

int main(){
    char s[101], t[101];
    scanf("%s %s", s, t);
    int s_len = strlen(s), t_len = strlen(t);
    qsort(s, s_len, sizeof(char), cmpAsc);
    qsort(t, t_len, sizeof(char), cmpDsc);
    if(strcmp(s, t) < 0){
        printf("Yes");
    }else{
        printf("No");
    }

    return 0;
}
