#include <stdio.h>

int main()
{
  unsigned long long int n,i,x,sum=0,count=0,flag=0;
   char a[1000000];
   
   
gets(a);
for(i=0;i<strlen(a);)
{
    if(a[i]=='e')
    {
    if(a[i]=='e'&& a[i+1]=='r' && a[i+2]=='a' && a[i+3]=='s' && a[i+4]=='e'&& a[i+5]=='r')
    {
        i+=6;
    }else{
        if(a[i]=='e'&& a[i+1]=='r' && a[i+2]=='a' && a[i+3]=='s' && a[i+4]=='e')
        {
        i+=5;
        }
        else{
            flag=1;
            break;
        }
    }
    }else{
        if(a[i]=='d')
        {
            if(a[i]=='d'&& a[i+1]=='r' && a[i+2]=='e' && a[i+3]=='a' && a[i+4]=='m'&& a[i+5]=='e' && a[i+6]=='r' && a[i+7]!='a' && a[i+8]!='s')
         {
        i+=7;
       }else{
          if(a[i]=='d'&& a[i+1]=='r' && a[i+2]=='e' && a[i+3]=='a' && a[i+4]=='m'){
        i+=5;
         } else{
             flag=1;
            break;
         }
       }
        }else{
            flag=1;
            break;
        }
        
    }
}
if(flag==1)
{
    printf("NO");
}else{
    printf("YES");
}
    return 0;
}
