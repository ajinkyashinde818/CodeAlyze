#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
int main(void){
    int length;
    char *string;
    int k;

    scanf("%d",&length);
    string=(char *)malloc(sizeof(char)*length);
    scanf("%s",string);
    scanf("%d",&k);
    int i;
    for(i=0;i<length;i++){
        if(string[i]!=string[k-1]){
            string[i]='*';
        }
    }
    printf("%s",string);
    return 0;
}
