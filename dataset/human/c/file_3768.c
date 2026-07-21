#include <stdio.h>
    #include <math.h>
     
    int main(){            
      long a,b,r,tmp;
      long ans;
      int i;

      scanf("%ld %ld",&a,&b);

      ans = a * b;
 
      /* 自然数 a > b を確認・入替 */
  	  if( a < b ){
      	tmp = a;
   		a = b;
    	b = tmp;
      }
 
      /* ユークリッドの互除法 */
  	  r = a % b;
      while(r!=0){
      	a = b;
    	b = r;
    	r = a % b;
  	  }
      
      printf("%ld",ans/b);
      
      return 0;
    }
