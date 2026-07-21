#include<stdio.h>

int main(){
      int n ;
      scanf("%d", &n) ;
      int D1[n], D2[n] ;
      for(int i=0; i<n; i++)
            scanf("%d%d", &D1[i], &D2[i]) ;
      int ans = 0 ;
      for(int i=0; i<n-2; i++) 
      {
              if(D1[i]==D2[i]&&D1[i+1]==D2[i+1]\
              &&D1[i+2]==D2[i+2])
              {
                    ans = 1 ;
                    break ;
              }
      }
      if(ans == 0)
            printf("No") ;
      else 
            printf("Yes") ;
      return 0 ;
}
