#include<stdio.h>
#include<string.h>

int main(void)
{
  char str0[4];
  char str1[]="abc",str2[]="acb",str3[]="bac",str4[]="bca",str5[]="cab",str6[]="cba";
  
  scanf("%s",str0);
  
  if( (strcmp(str0,str1)==0) || (strcmp(str0,str2)==0) || (strcmp(str0,str3)==0) || (strcmp(str0,str4)==0) || (strcmp(str0,str5)==0) || (strcmp(str0,str6)==0) ){
    printf("Yes");
  }else{
    printf("No");
  }
    
  return 0;
      
}
