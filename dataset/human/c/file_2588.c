#include <stdio.h>
int main(void)
{
	int a;
  char s[3];
  for(int i=0;i<3;i++){
    scanf("%s",&s[i]);
  }
  if(s[0]=='a'){
    if(s[1]=='b'){
      if(s[2]=='c'){
        printf("Yes");
      }else{
        printf("No");
      }
    }else if(s[1]=='c'){
        if(s[2]=='b'){
          printf("Yes");
        }else{
          printf("No");
        }
    }else if(s[1]=='a'){
      printf("No");
    }
  }else if(s[0]=='b'){
    if(s[1]=='a'){
      if(s[2]=='c'){
        printf("Yes");
      }else{
        printf("No");
      }
    }else if(s[1]=='c'){
      if(s[2]=='a'){
        printf("Yes");
      }else{
        printf("No");
      }
    }else if(s[1]=='b'){
      printf("No");
    }
  }else if(s[0]=='c'){
    if(s[1]=='a'){
      if(s[2]=='b'){
        printf("Yes");
      }else{
        printf("No");
      }
    }else if(s[1]=='b'){
      if(s[2]=='a'){
        printf("Yes");
      }else{
        printf("No");
      }
    }else if(s[1]=='c'){
      printf("No");
    }
  }else{
    printf("No");
  }
  return 0;
}
