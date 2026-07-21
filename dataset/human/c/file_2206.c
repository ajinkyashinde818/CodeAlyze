#include<stdio.h>
int main(void){
 char s[100001];
 char f[1000000];
 char b[1000000];
 int flength=0,blength=0,slength=0;
 int q;
 int q1,q2,state=0,i;
 char q3;
 scanf("%s",s);
 scanf("%d",&q);
 for(i=0;i<q;i++){
   scanf("%d",&q1);
   if(q1==1){
     if(state){
       state=0;
     }else{
       state=1;
     }
   }else{
     q2=' ';
     q3=' ';
     while(q2==' '||q2=='\n')
      scanf("%d",&q2);
     while(q3==' '||q3=='\n')
      scanf("%c",&q3);
     q2+=state;
     if(q2%2==0){
       b[blength++]=q3;
     }else{
       f[flength++]=q3;
     }
   }
 }
 //printf("state=%d\n",state);
 if(state){
   for(i=blength-1;i>=0;i--){
     printf("%c",b[i]);
   }
   for(i=0;i<100001;i++){
     if(s[i]==0){
       slength=i;
       break;
     }
   }
   for(i=slength-1;i>=0;i--){
     printf("%c",s[i]);
   }
   printf("%s\n",f);
 }else{
   for(i=flength-1;i>=0;i--){
     printf("%c",f[i]);
   }
    printf("%s%s\n",s,b);
 }
 return 0;
}
