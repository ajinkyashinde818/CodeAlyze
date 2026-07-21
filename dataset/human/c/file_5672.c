#include <stdio.h>
#include <climits>

int main(){
    int n, temp, min = INT_MAX, ans = INT_MIN;
    scanf("%d",&n);

    for(int i = 0; i < n; i++){
        scanf("%d", &temp);
        
        if((temp - min) > ans){
            ans = (temp - min);
        }
        
        if(temp < min){
            min = temp;
        }
    }    
    printf("%d\n",ans);
}
