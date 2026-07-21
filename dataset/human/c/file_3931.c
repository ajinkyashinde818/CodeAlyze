#include<stdio.h>
int main()
{
    int a, b, k,i, j=1, x[101];

    scanf("%d %d %d", &a, &b, &k);

    if(a<b){
        for(i=a; i>=1; --i){

            if(a%i==0 && b%i==0){
                x[j] = i;
                j++;
            }

        }
    }else if(a>b){
        for(i=b; i>=1; i--){

            if(a%i==0 && b%i==0){
                x[j] = i;
                j++;
            }

        }
    }else if(a==b){
        for(i=a; i>=1; i--){

            if(a%i==0){
                x[j] = i;
                j++;
            }

        }
    }


    printf("%d\n", x[k]);

    return 0;
}
