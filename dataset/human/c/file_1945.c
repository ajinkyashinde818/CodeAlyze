#include<stdio.h>

int bonuse(int *a, int *c){
    int tmp = 0;
    do{
        if(*(a + 1) - *a == 1){
            tmp += c[*a - 1];
        }
        *a++;
    }while(*(a + 1));

    return tmp;
}

int sumb(int *b){
    int tmp = 0;
    int i;

    do{
        tmp += *b;
    }while(*b++);

    return tmp;
}

int main(void){
    int n;
    int a[100] = {0};
    int b[100] = {0};
    int c[100] = {0};
    int i;

    scanf("%d", &n);
    for(i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
     for(i = 0; i < n; i++){
        scanf("%d", &b[i]);
    }
     for(i = 0; i < n - 1; i++){
        scanf("%d", &c[i]);
    }

    printf("%d", sumb(b) + bonuse(a, c));

    return 0;
}
