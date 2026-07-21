#include <stdio.h>

int CanMove(int *books, int n, int key, int m)
{
    int i;
    int left;
    
    i = 0;
    while (m-- && i != n){
        left = key;
        while (left >= books[i] && i != n){
            left -= books[i++];
        }
    }
    
    if (i != n){
        return (0);
    }
    return (1);
}

int main(void)
{
    int i;
    int n, m;
    int books[101];
    int min, max, search;
    
    while (1){
        scanf("%d%d", &m, &n);
        
        if (m + n == 0){
            break;
        }
        
        for (i = 0; i < n; i++){
            scanf("%d", &books[i]);
        }
        
        min = 0;
        max = 1500000;
        while (min != max){
            search = (min + max) / 2;
            
            if (CanMove(books, n, search, m)){
                max = search;
            }
            else {
                min = search + 1;
            }
        }
        
        printf("%d\n", min);
    }
    
    return (0);
}
