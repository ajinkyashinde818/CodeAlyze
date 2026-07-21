#include<stdio.h>
#include<string.h>
int main(void){

    char a[4];

    scanf("%s",a);
    if(a[0]=='a'||a[0]=='b'||a[0]=='c'){
        if((a[1]=='a'||a[1]=='b'||a[1]=='c')&&(a[1]!=a[0])){
            if((a[2]=='a'||a[2]=='b'||a[2]=='c')&&(a[2]!=a[0])&&(a[2]!=a[1])){
                printf("Yes\n");
            }
            else{
                printf("No\n");
            }
        }
        else{
            printf("No\n");
        }
    }
    else{
        printf("No\n");
    }
    return 0;
}
