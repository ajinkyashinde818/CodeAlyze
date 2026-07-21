#include<stdio.h>
int main()
{
int a,b,max,j;
  max=0;
  scanf("%d %d",&b,&a);
int c[a],d[a];
  scanf("%d",&c[0]);
    for(j=0;j<a-1;++j)
    {scanf("%d",&c[j+1]);
     d[j]=c[j+1]-c[j];
     if(d[j]>max) max=d[j];
    }
  d[a-1]=b+c[0]-c[a-1];
  if(d[a-1]>max) max=d[a-1];
  
  
 printf("%d",b-max); 
return 0;
}
