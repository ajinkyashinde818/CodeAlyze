#include<stdio.h>
#include<math.h>

int main(void){
    int s,n,p,i,j,y;
    double a;
    while(scanf("%d",&p) , p != 0){
        s = 0;
        n = 1;
        for (i = 1;i <= p;i++){
            while(1){
                n++;
                y = 1;
                a = n;
                a = sqrt(a);
                for(j = 2;j <= a;j++){
                    if(!(n % j)){
                        y = 0;
                        break;
                    }
                }
                if(y){
                    s += n;
                    break;
                }
            }
        }
        printf("%d\n" , s);
    }
    return 0;
}
