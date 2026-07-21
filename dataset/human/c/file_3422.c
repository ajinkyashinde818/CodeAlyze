#include<stdio.h>

int func(char* p, char* t){
    int n = 0;
    while(*(t+n) != '\0'){
        if(*(p+n) != *(t+n)){
            return 0;
        }
        n++;
    }
    return 1;
}

int match(char* p){
    if(*p == '\0'){
        return 1;
    }
    int dream   = 0;
    int dreamer = 0;
    int erase   = 0;
    int eraser  = 0;
    if(func(p, "dream") == 1){
        dream = match(p+5);
    }
    if(func(p, "dreamer") == 1){
        dreamer = match(p+7);
    }
    if(func(p, "erase") == 1){
        erase = match(p+5);
    }
    if(func(p, "eraser") == 1){
        eraser = match(p+6);
    }
    if(dream == 1 || dreamer == 1 || erase == 1 || eraser == 1){
        return 1;
    }else{
        return 0;
    }
}

int main(){
    char s[100001];
    scanf("%s", s);
    int buf = match(s);
    if(buf == 1){
        printf("YES");
    }else{
        printf("NO");
    }

    return 0;
}
