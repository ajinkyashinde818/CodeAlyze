#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
  int H,W,i,j;
  char str[50],s[60][60],*p;
  
  fgets(str,sizeof(str),stdin);
  p=strtok(str," \n");
  H=atoi(p);
  p=strtok(NULL," \n");
  W=atoi(p);
  
  for(i=0;i<H;i++){
    fgets(s[i],sizeof(s[i]),stdin);
  }
  
  for(i=0;i<H;i++){
   for(j=0;j<W;j++){
    if(i==0 && j==0 && s[i][j]=='#'){
      if(s[i+1][j]=='.' && s[i][j+1]=='.'){
       printf("No\n");
        return 0;
      }
    }else if(i==0 && j==W-1 && s[i][j]=='#'){
      if(s[i+1][j]=='.' && s[i][j-1]=='.'){
       printf("No\n");
        return 0;
      }
    }else if(i==0 && s[i][j]=='#'){
      if(s[i+1][j]=='.' && s[i][j-1]=='.' && s[i][j+1]=='.'){
        printf("No\n");
        return 0;
      }
    }else if(i==H-1 && j==0 && s[i][j]=='#'){
      if(s[i-1][j]=='.' && s[i][j+1]=='.'){
       printf("No\n");
        return 0;
      }
    }else if(i==H-1 && j==W-1 && s[i][j]=='#'){
      if(s[i-1][j]=='.' && s[i][j-1]=='.'){
       printf("No\n");
        return 0;
      }
    }else if(i==H-1 && s[i][j]=='#'){
      if(s[i-1][j]=='.' && s[i][j-1]=='.' && s[i][j+1]=='.'){
        printf("No\n");
        return 0;
      }
    }else if(j==0 && i!=0 && i!=H-1  && s[i][j]=='#'){
       if(s[i-1][j]=='.' && s[i+1][j]=='.' && s[i][j+1]=='.'){
         printf("No\n");
         return 0;
       }
    }else if(j==W-1 && i!=0 && i!=H-1  && s[i][j]=='#'){
       if(s[i-1][j]=='.' && s[i+1][j]=='.' && s[i][j-1]=='.'){
         printf("No\n");
         return 0;
       }
    }else if(s[i][j]=='#'){
        if(s[i-1][j]=='.' && s[i+1][j]=='.' && s[i][j-1]=='.' 
          && s[i][j+1]=='.'){
          printf("No\n");
          return 0;
        }
         
       }
     
   }
  }
    
  printf("Yes\n");
  
 return 0; 
}
