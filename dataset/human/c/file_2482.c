#include<stdio.h>

int main(void)
{
  char S[3];
  
  scanf("%s", S);
  
  if(S[0] == 'a'){
    if(S[1] == 'b'){
      if(S[2] == 'c') printf("Yes\n");
      else printf("No\n");
    }
    else if(S[1] == 'c'){
      if(S[2] == 'b') printf("Yes\n");
      else printf("No\n");
    }
    else printf("No\n");
  }
    
  if(S[0] == 'b'){
    if(S[1] == 'a'){
      if(S[2] == 'c') printf("Yes\n");
      else printf("No\n");
    }
    else if(S[1] == 'c'){
      if(S[2] == 'a') printf("Yes\n");
      else printf("No\n");
    }
    else printf("No\n");
  }
  
  if(S[0] == 'c'){
    if(S[1] == 'a'){
      if(S[2] == 'b') printf("Yes\n");
      else printf("No\n");
    }
    else if(S[1] == 'b'){
      if(S[2] == 'a') printf("Yes\n");
      else printf("No\n");
    }
    else printf("No\n");
  }  
  
  return 0;
}
