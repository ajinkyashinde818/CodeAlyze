#include <stdio.h>

int main(void){
    char line[100];
    int i=0,sign=0;
    scanf("%s",line);
    while(line[i]){
        if(line[i] == '9')
            sign=1;
        i++;
    }
    if(sign)
        puts("Yes");
    else
        puts("No");


  return 0;
}
