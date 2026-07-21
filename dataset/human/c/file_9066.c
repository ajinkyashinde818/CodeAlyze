#include<stdio.h>

int main(){

    int person;
    int high_restrict;
    int permit = 0;

    scanf("%d%d\n",&person,&high_restrict);
    int high_array[person];
    for(int i = 0; i < sizeof(high_array)/sizeof(int); i++){
        scanf("%d\n",&high_array[i]);
        if(high_restrict <= high_array[i]){
            permit++;
        }
    }
    printf("%d\n",permit);
    return 0;
}
