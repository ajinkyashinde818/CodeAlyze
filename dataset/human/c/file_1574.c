#include<stdio.h>
#include <stdlib.h>
#include <string.h>

//   enum hex { A , B , C, D, E, F };

int main()
{
//    enum hex henkan;

    char X;
    char Y;
 
 // 整数の入力
    scanf("%c %c", &X, &Y);
if(X<Y){
    printf("<\n");
    } else if (X==Y){
    printf("=\n");
    } else {
    printf(">\n");
   }            
     
    return 0;
}
