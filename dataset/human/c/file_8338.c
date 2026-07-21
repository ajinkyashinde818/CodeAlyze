#include<stdio.h>

int main(){
    char s[11];
    int i, in1, in2;

    scanf("%d", &in1);
    scanf("%s", s);
    scanf("%d", &in2);

    for(i=0; i<in1; i++){
        if(s[i] != s[in2-1]){
            s[i] = '*';
        }
    }

    printf("%s", s);

    return 0;
}
