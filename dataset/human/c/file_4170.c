#include <stdio.h>

int main(){
    int a,b,min,k,count = 0;
    scanf("%d %d %d",&a,&b,&k);
    if(a < b) min = a;
    else min = b;
    int str[min];
    for(int i = min; i > 0; i--){
        if(a % i == 0 && b % i == 0){
            str[count] = i; 
            count++;
        }
        else continue;
    }
    printf("%d\n",str[k-1]);
    return 0;
}
