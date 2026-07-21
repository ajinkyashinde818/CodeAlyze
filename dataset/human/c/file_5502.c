#include <stdio.h>
#include <math.h>

#define true 1
#define false 0

int IsPrime(int n){
    if(n < 2) return false;
    else if(n==2) return true;
    else if(n%2 == 0) return false;
    
    double sqrtNum = sqrt(n);
    for (int i = 3; i <= sqrtNum; i += 2){
        if (n % i == 0){
            return false;
        }
    }
    return true;
}




int main(){
    
    int num=1,i,cnt,sum;
    
   while(1){
        scanf("%d",&num);
        if(num == 0){
            break;
        }
        cnt = 2;
        sum = 0;
        while(num>0){
            if(IsPrime(cnt)==true){
                sum += cnt;
                num--;
            }
            cnt++;
        }
        printf("%d\n",sum);
    }

	return 0;
}
