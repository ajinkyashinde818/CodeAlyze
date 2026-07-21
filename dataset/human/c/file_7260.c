#include <stdio.h>
int main()
{
 int h,w;
 int i,j,k;
 while(1){
          scanf("%d %d",&h,&w);
          if(!h && !w) break;
          for(i=1; i<=h; i++){
               if(i%2){
                           for(j=1; j<=w; j++){
                                if(j%2) putchar('#');
                                else      putchar('.');
                           }
               }
                else     {
                             for(j=1; j<=w; j++){
                             if(j%2) putchar('.');
                             else      putchar('#');
                             }
                            }
 putchar('\n');
            }
  putchar('\n');
}
return 0;
}
