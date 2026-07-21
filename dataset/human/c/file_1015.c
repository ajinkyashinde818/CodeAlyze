#include <stdio.h>
#include <string.h>

int main() {

  int n,k[200] = {0};
  int i,j,l,o,t;
  char str[101];


  while(1) {
    scanf("%d",&n);

    if(n==0) break;

    for(i=0;i<n;i++) {

      scanf("%d",&k[i]);
    }

    scanf("%s",str);

    o = -1;
    for(i=0;i<strlen(str);i++) {
      //ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijKlmnopqrstuvwxyz
      o++;
      if(o == n) o = 0;
    
      t = k[o];
      while(1) {
	
	if(str[i] - t < 'A' && str[i] >= 'A' && str[i] <= 'Z') {
	  t = 'A' - (str[i] - t)-1;
	  str[i] = 'z';
	} else if(str[i] - t < 'a' && str[i] >= 'a' && str[i] <= 'z'){
	  t = 'a' - (str[i] - t)-1;
	  str[i] = 'Z';
	}else break;
      }
      // printf("t = %d\n",t);
      str[i] = str[i] - t;
      
    }

    printf("%s\n",str);

  }

  return 0;

}
