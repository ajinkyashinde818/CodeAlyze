#include<stdio.h>
#include<stdlib.h>

#define BUFSIZE 200000
#define INTMIN -2000000000

int main(){
    int n, buf[BUFSIZE];
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", buf + i);
    }
    int min = buf[0];
    int max = INTMIN;
    for(int i = 1; i < n; i++){
        if(max < buf[i] - min)max = buf[i] - min;
        if(min > buf[i])min = buf[i];
    }
    printf("%d\n", max);
}
