#include<stdio.h>
#include<limits.h>

int main(void) {
    int size, i, j, min=INT_MAX, max_dif=INT_MIN, dif;
    scanf("%d", &size);
    
    int data[size];
    scanf("%d", &data[0]);
    
    min = data[0];
    for(i=1; i<size; i++) {
        scanf("%d", &data[i]);
        
        dif = data[i] - min;
        if(dif > max_dif) max_dif = dif;

        if(min > data[i]) min = data[i];
        
    }
    
    printf("%d\n", max_dif);
    
    return 0;
}
