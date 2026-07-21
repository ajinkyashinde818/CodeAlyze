#include<stdio.h>

int main()
{
    char X[2];  scanf("%s", X);
    char Y[2];  scanf("%s", Y);

    if((X[0] - Y[0]) > 0){
        puts(">");
    }
    else{
        if((X[0] - Y[0]) < 0){
            puts("<");
        }
        else{
            puts("=");
        }
    }
  
    return 0;
}
