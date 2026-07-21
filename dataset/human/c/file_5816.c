#include <stdio.h>
int max(int i, int j);
int min(int i, int j);

int main(void){
    int i, j;
    int n;
    int R[200000];
    int max_v;
    int min_past;
    int tmp;
    scanf("%d", &n);
    for(i = 0; i < n; ++i){
        scanf("%d", &R[i]);
    }
    max_v = R[1]-R[0];
    min_past = R[0];
    for(i = 1; i < n; ++i){
            max_v = max(max_v, R[i]-min_past);
            min_past = min(min_past, R[i]);
    }
    printf("%d\n", max_v);
    return 0;
}

int max(int i, int j){
    if(i > j) return i;
    else return j;
}

int min(int i, int j){
    if(i < j) return i;
    else return j;
}
