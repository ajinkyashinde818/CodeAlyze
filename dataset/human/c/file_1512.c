#include <stdio.h>

int  trans(char A) {
int a ;
   switch (A) {
      case 'A':  
         a = 10; break;
      case 'B': 
           a = 11; break;
      case 'C':  
           a = 12; break;
      case 'D': 
           a = 13; break;
      case 'E': 
           a = 14; break;
      case 'F': 
             a = 15; break;
      default:
              break;
  }
return  a;
}

int main()
{
  char x, y;
  scanf("%c %c",  &x, &y);

 if (trans(x) > trans(y)) {
   printf(">");
} else if (trans(x) == trans(y)){
   printf("=");
} else {
   printf("<");
}
  return 0;
}
