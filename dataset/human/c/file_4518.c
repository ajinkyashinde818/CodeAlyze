#include <stdio.h>
int main(int argc, char const *argv[]) 
{
  int n,i,j;
  scanf("%d",&n );
  int a[n],b[n],c=0,l=0;
  for( i=1,j=1; i<=n,j<=n; i++,j++)
     {
         scanf("%d %d",&a[i],&b[j]);
        if (a[i]==b[j])
        {
           c++;
           if (c>=3)
           {
              l++;
           }
           
        }
        else
        {
            c=0;
        }
        
        
     }
     if (l>0)
     {
         printf("Yes\n");
     }
     else
     {
        printf("No\n");
     }
     
/*          MD OMOR FARUK
            Daffodil International University(CSE)
            Contact:farukprimate@gmail.com
*/     



return 0;
}
