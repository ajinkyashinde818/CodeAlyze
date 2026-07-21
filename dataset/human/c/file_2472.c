#include <stdio.h>

int main(void){

    char A[100];
    scanf("%s", A);

    if(A[0] == 'a' && A[1] == 'b' && A[2] == 'c'){
        puts("Yes");
    } else if(A[0] == 'a' && A[1] == 'c' && A[2] == 'b'){
        puts("Yes");
    } else if(A[0] == 'b' && A[1] == 'a' && A[2] == 'c'){
        puts("Yes");
    } else if(A[0] == 'b' && A[1] == 'c' && A[2] == 'a'){
        puts("Yes");
    } else if(A[0] == 'c' && A[1] == 'a' && A[2] == 'b'){
        puts("Yes");
    } else if(A[0] == 'c' && A[1] == 'b' && A[2] == 'a'){
        puts("Yes");
    }else{
        puts("No");
    }


    return 0;
}
