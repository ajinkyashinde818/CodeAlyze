#include <stdio.h>
#include <stdlib.h>

int ppp(int* arr, int n){
    int a = -1000000003;
    int b = arr[0];//min number
    int c = 0;//to store the temp number
    for(int i=1; i<n; i++){
        if(arr[i] < b) b = arr[i];
        c = arr[i] - b;
        if(c>a) a = c;
    }
    return a;
}
int test(int *arr, int n){
    int i=0;
    for(i=1; i<n; i++){
        if(arr[i]-arr[i-1]>0) return 0;
    }
    return 1;
}
int xxx(int*arr, int n){
    int a = -1000000003;
    int c = 0;//to store the temp number
    for(int i=0; i<n-1; i++){
        c = arr[i+1] - arr[i];
        if(c>a) a = c;
    }
    return a;
}

int main(int argc, char** argv) {
    int N, counter;
    scanf("%d", &N);
    int arr[N];
    for(counter=0; counter<N;counter++){	
	scanf("%d", &arr[counter]);
    }
    int result;
    if (test(arr, N)==1){
        result = xxx(arr, N);
    }
    else result = ppp(arr, N);
    printf("%d\n", result);
    
    return 0;
}
