#include <stdio.h>
     
    int main(void)
    {  
       int ans,i,j,n,d,x;
       int a[100];
     
       scanf("%d",&n);
       scanf("%d%d",&d,&x);
          ans=x;
       for(i=0;i<n;i++)
          scanf("%d",&a[i]);
       
       for(i=0;i<n;i++){
          for(j=0;j<d;j=j+a[i])
                ans++;
       }     
       
        printf("%d\n",ans);
     
       return 0;
    }
