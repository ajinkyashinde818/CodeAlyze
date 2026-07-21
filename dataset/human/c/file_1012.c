#include <stdio.h>
#include <string.h>
#include <math.h>

int main(void)
{
  int n,i,j,k,def,len;
  char alp[]="abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

  for(;;){
    scanf("%d", &n);
    if(!n) break;

    int key[100]; char code[101]; 
    for(i=0;i<n;i++){
      scanf("%d", &key[i]);
    }
    scanf("\n%s", code);
    len=strlen(code);
    for(i=0,k=0;k<len;i=(i+1)%n,k++){
      for(j=0;j<52;j++){
	if(code[k]==alp[j]){
	  if(j-key[i]>=0){
	    putchar(alp[j-key[i]]); break;
	  }
	  else{
	    def=abs(j-key[i]); putchar(alp[52-def]); break;
	  }
	}
      }
    }
    puts("");
  }	

  return 0;
}
