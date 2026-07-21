#include<stdio.h>
int main()
{
    int n,a=0,b=0,c=0;
    char s[101];
    scanf("%s",s);
 for(n=0;n<3;n++){
 if(s[n]=='a'){a++;}
   else if(s[n]=='c'){c++;}
     else if(s[n]=='b'){b++;}
 }
 if(a==1&&b==1&&c==1){
   printf("Yes");
 }
 else{
   printf("No");
 } 
    return 0;
}
