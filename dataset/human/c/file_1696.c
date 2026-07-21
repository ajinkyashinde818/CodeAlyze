#include<stdio.h>

int main(){
    int N; //N種類2 <= N <= 20
    int a[20];
    int b[50];
    int c[50];
    int i = 1;

    int Satisfied = 0;

    scanf("%d", &N);
    
    a[0] = -1;
    b[0] = -1;
    c[0] = -1;

    //input
    for(i = 1; i <= N; i++){
        scanf("%d", &a[i]);
    }

    for(i = 1; i <= N; i++ ){
        scanf("%d", &b[i]);
    }

    for(i = 1; i < N; i++ ){
        scanf("%d", &c[i]);
    }

    for(i = 1; i <= N; i++){
        Satisfied += b[a[i]];
        if(a[i] == a[i - 1] + 1){
            Satisfied += c[a[i] - 1];
        }
    }

    printf("%d\n", Satisfied);

    return 0;

}
