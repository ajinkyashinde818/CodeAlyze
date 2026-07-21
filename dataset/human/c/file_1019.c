#include <stdio.h>
#include <string.h>
int main(void){
    int i,n,k[100];
    char s[101],c[52];
    
    for(i=0;i<26;i++){
        c[i]=97+i;
    }
    for(i=26;i<52;i++){
        c[i]=65+i-26;
    }
    for(;;){
        scanf("%d",&n);
        if(n==0){
            break;
        }
        for(i=0;i<n;i++){
            scanf("%d",&k[i]);
        }
        scanf("%s",s);
        
        for(i=0;i<strlen(s);i++){
            if(s[i]<=90){
                printf("%c",c[((int)s[i]-k[i%n]+13)%52]);
            }else if(s[i]>=97){
                printf("%c",c[((int)s[i]-45-k[i%n])%52]);
            }
        }
        printf("\n");
    }
    return 0;
}
