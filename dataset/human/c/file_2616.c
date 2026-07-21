#include<stdio.h>
 int main(void)
 {
     char s[3];
     int i,j=0,k=0,l=0;

     scanf("%s",s);

     for(i=0;i<3;i++){
       if(s[i]=='a') j++;
       if(s[i]=='b') k++;
       if(s[i]=='c') l++;
     }

     if((j==1)&&(k==1)&&(l==1)) printf("Yes\n");
     else printf("No\n");

     return 0;
 }
