#include <stdio.h>

char s[3], abc[5];
bool f= true;

int main(){
    scanf("%s", s);
    for(int i=0; i<3; i++){
        if(abc[s[i]-'a'] > 0)
            f = false;
        else
            abc[s[i]-'a'] += 1;
    }
    if(f)
        printf("Yes\n");
    else
        printf("No\n");
}
