#include<stdio.h>
#include<stdlib.h>
#include<math.h>




int main(void){
    char s[4];
    scanf("%s",s);
    int i,counter1 = 0,counter2 = 0;
    for(i=0;i<3;i++){
        counter1 += (int)s[i];
    }
    counter2 = 'a' + 'b' + 'c';
    if(counter1 == counter2){
        printf("Yes\n");
    }
    else{
        printf("No\n");
    }
    
    return 0;

}
