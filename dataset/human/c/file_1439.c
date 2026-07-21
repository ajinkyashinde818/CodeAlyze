#include<stdio.h>
int main()
{
    int a,b,c;
    scanf("%d",&a);
    b = a/10;
    c = a - b*10;
    
    if(b==9){
      printf("Yes\n");
      return 0;
    }else if(c==9){
      printf("Yes\n");
      return 0;
    }
    printf("No\n");
    return 0;
}
