#include<stdio.h>
int main()
{
char a[3];
  scanf("%3s",a);
if(a[0]=='a' && a[1]=='b' && a[2]=='c') printf("Yes");
else if(a[0]=='a' && a[1]=='c' && a[2]=='b') printf("Yes");
else if(a[0]=='b' && a[1]=='a' && a[2]=='c') printf("Yes");  
else if(a[0]=='b' && a[1]=='c' && a[2]=='a') printf("Yes");  
else if(a[0]=='c' && a[1]=='b' && a[2]=='a') printf("Yes");  
else if(a[0]=='c' && a[1]=='a' && a[2]=='b') printf("Yes");  
else printf("No");
  
return 0;
}
