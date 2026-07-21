#include <stdio.h>
int main(void){
    char S[4];
    int i;
    for(i=0;i<3;i++)
    scanf("%c",&S[i]);
    
     if(S[0]=='a'&&S[1]=='b'&&S[2]=='c')printf("Yes");
      else if(S[0]=='a'&&S[1]=='c'&&S[2]=='b')printf("Yes");
   else if(S[0]=='b'&&S[1]=='a'&&S[2]=='c')printf("Yes");
   else if(S[0]=='b'&&S[1]=='c'&&S[2]=='a')printf("Yes");
     else if(S[0]=='c'&&S[1]=='a'&&S[2]=='b')printf("Yes");
  else if(S[0]=='c'&&S[1]=='b'&&S[2]=='a')printf("Yes");
  else{printf("No");}
  
    return 0;
}
