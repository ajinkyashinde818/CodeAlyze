#include <stdio.h>
#include <string.h>

int main(){
    char a[]="abc",b[]="bac",c[]="bca",d[]="cab",e[]="cba",f[]="acb";
    char s[4];
    
    scanf("%s",s);
    
    if(strcmp(s,a)==0 || strcmp(s,b)==0 || strcmp(s,c)==0 || strcmp(s,d)==0 || strcmp(s,e)==0 || strcmp(s,f)==0){
        printf("Yes\n");
    }
    
    else{
        printf("No\n");
    }
    
    
    return 0;
}
