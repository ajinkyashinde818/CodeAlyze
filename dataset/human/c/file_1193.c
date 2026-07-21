#include <stdio.h>
#include <string.h>

int main (void){
      
   char s[128];
   char t[128];
   
   scanf("%s", s);
   scanf("%s", t);
    
   int lens = strlen(s);
   int lent = strlen(t);
   //bubble sort
   for(int i = 0; i < lens; i++){

        for(int j = i+1; j < lens; j++){
          
          if(s[i] > s[j]){
            char tmp = s[i];
            s[i] = s[j];
            s[j] = tmp;
          }
             
        }
   }
    
   for(int i = 0; i < lent; i++){

        for(int j = i+1; j < lent; j++){
         
          if(t[i] < t[j]){
            char tmp = t[i];
            t[i] = t[j];
            t[j] = tmp;
          }
             
        }
   }

    if(strcmp(s,t) < 0)    
      printf("Yes");
    else
      printf("No");
   return 0;
    
}
