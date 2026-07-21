// 最大の利益
#include <stdio.h>

int main(void)
{
    int n, i, j;
    scanf("%d", &n);

    int array[n];
    for(i=0; i<n; i++){
        scanf("%d", &array[i]);
    }
    int maxv = array[1] - array[0];
    int minv = array[0];
    for(j=1; j<n; j++){
        if(maxv < array[j] - minv){
            maxv = array[j] - minv;
        }
        if(minv > array[j]){
            minv = array[j];
        }
    }
    printf("%d\n", maxv);

    return 0;   
}
