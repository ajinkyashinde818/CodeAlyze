#include<stdio.h>
#include<math.h>

int main(){
    int num, i;
    long int input[100000];
    long int ans = 0;
    long int min = 1000000000;
    int count = 0;

    scanf("%d", &num);
    for(i=0; i<num; i++){
        scanf("%ld", &input[i]);
        ans = ans + abs(input[i]);
        if(input[i] < 0){
            count += 1;
        }
        if(min > abs(input[i])){
            min = abs(input[i]);
        }
    }
    
    if((count%2)==0){
        printf("%ld", ans);
    } else{
        printf("%ld", (ans-min*2));
    }

    return 0;
}
