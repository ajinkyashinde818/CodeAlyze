#include<stdio.h>

int main(int argc, char** argv) {
    char input[2];
    int i;

    i = scanf("%s", input);                                                                                 
    for (i = 0; i < 2; i++) {                                                                               
        if (input[i] == '9') {                                                                              
            printf("Yes\n");
            return 0;
        }
    }
    printf("No\n");
    return 0;
}
