#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 
int main() {
    int n;
    scanf("%d", &n);
    int a[n], b[n];
    int i;
    int temp = 0;
    int check = 0;
    int left = 0, right = n-1;
    
    for(i = 0; i < n; i ++){
    scanf("%d", &a[i]);
    }
    for(i = 0; i < n; i ++){
    scanf("%d", &b[n - i - 1]);
    }
    
    for (i = 0; i < n; i ++) {
        if (a[i] == b[i]) {
            if(a[left] != b[i] && b[left] != a[i]){
                temp = b[i];
                b[i] = b[left];
                b[left] = temp;
                left ++;
            }else if(a[right] != b[i] && b[right] != a[i]){
                temp = b[i];
                b[i] = b[right];
                b[right] = temp;
                right --;
            }else{
                check = -1;
                break;
            }
            }
    }
    
    if(check == 0){
        printf("Yes\n");
        for (i = 0; i < n; i ++) {
            printf("%d ", b[i]);
        }
    }else{
        printf("No\n");
    }
    
    return 0;
}
