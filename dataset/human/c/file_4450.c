#include<stdio.h>
#include<string.h>

int main() 
{
  int dice1, dice2 = 0;
  int cnt = 0;
  int flag = 0;
  int i_rc = 0;
  i_rc = scanf("%d", &cnt);
  
  for(int ii = 0; ii < cnt; ii++) {
   	i_rc = scanf("%d", &dice1); 
       	i_rc = scanf("%d", &dice2); 
    
    if (dice1 == dice2) {
      flag++;
    } else {
     flag = 0; 
    }
    
    if (flag == 3) {
      printf("Yes");
      break;
    } 
    
  }
  
  if (flag != 3) {
   printf("No"); 
  }
  
  return 0;
  
}
