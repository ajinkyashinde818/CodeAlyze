#include <stdio.h>

int main(){
    int N;
    scanf("%d", &N);

    char S[N];
    scanf("%s", &S);

    int a;
    scanf("%d", &a);

    for (int i=0; i<N; i++){
        if (S[i] != S[a-1]){
            printf("*");
        }else{
           printf("%c", S[i]); 
        }
    }

    return 0;
}
