#include<stdio.h>
#include<math.h>

int main(void){
    long long N;
    int answer=0,count=0;
    scanf("%lld",&N);
    double sqrtN=sqrt(N);
    for(int i=2;i<=sqrtN;i++){
        while(N%i==0){
            N/=i;
            count++;
        }
        int j=1;
        while(count>=j){
            answer++;
            count-=j;
            j++;
        }
        count=0;
    }
    if(N>sqrtN){
        answer++;
    }
    printf("%d\n",answer);
    return 0;
}
