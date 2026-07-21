#include <stdio.h>
int main(){
    int input;
    while(1){
        scanf("%d",&input);
        if(input==0)break;
        int cnt=0;
        while(input>1){
            if(input%2==0){
                input/=2;
            }else{
                input=input*3+1;
            }
            cnt++;
        }
        printf("%d\n",cnt);
    }
    return 0;
}
