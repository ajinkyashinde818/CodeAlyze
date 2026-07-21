#include <stdio.h>
int main(void){
    int a,b,c;
    char str[10];
    scanf("%s", str);
    
    
    a=0;
    b=0;
    c=0;
    if(str[0]=='a')a++;
    if(str[0]=='b')b++;
    if(str[0]=='c')c++;
    
    if(str[1]=='a')a++;
    if(str[1]=='b')b++;
    if(str[1]=='c')c++;
    
    if(str[2]=='a')a++;
    if(str[2]=='b')b++;
    if(str[2]=='c')c++;
    
    if((a==1&&b==1)&&c==1){
      printf("Yes");
    }else printf("No");
    
    return 0;
}
