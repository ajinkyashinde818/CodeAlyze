#include <stdio.h>
int main(){
    char s[4];
    int a=0,b=0,c=0,i;
    scanf("%s",s);
    for(i=0;i<4;i++){
        if(s[i]=='a')a++;
        if(s[i]=='b')b++;
        if(s[i]=='c')c++;
    }
    if(a==b&&b==c)printf("Yes");
    else printf("No");
    return 0;
}
