#include <stdio.h>
#include <stdlib.h>

int max(int,int);

int main(int argc, char** argv) {
    int size;
    scanf("%d\n", &size);
    if(size < 2 || size > 200000)
        return (EXIT_FAILURE);
    int array[size];
    
    for(int i = 0; i < size; i++){
        scanf("%d", &array[i]);
        if(array[i]<1 || size > 100000000)
            return(EXIT_FAILURE);
    }
    
    int j = 1;
    int i = j - 1;
    int maxLoc = 0;
    int minLoc = 0;
    int profit = array[j] - array[i];
    for(;j < size; j++){
        i = j - 1;
        if(array[i]>=array[j]){
            if(profit<=0)
                profit = max(profit, array[j]-array[i]);
            if(array[minLoc]>array[j])
                minLoc = j;
        }
        else{
            if(array[j]>array[maxLoc])
                maxLoc = j;
            profit = max(profit, array[j] - array[minLoc]);
        }
    }
    
    
    printf("%d\n", profit);
    
    return (EXIT_SUCCESS);
}

int max(int a, int b){
    if(a > b)
        return a;
    return b;
}
