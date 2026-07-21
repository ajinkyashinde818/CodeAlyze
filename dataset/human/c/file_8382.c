#include<stdio.h>
 
int main(void)
{
    int num;
    char str[100];
    int k;
    
    scanf("%d", &num);
    scanf("%s", str);
    scanf("%d",&k);
    
    
    for(int i=0;i<num;i++){
        if(str[i]!=str[k-1])
            printf("*");
        else
            printf("%c",str[i]);
    }
    printf("\n");
    
    return 0;
}
