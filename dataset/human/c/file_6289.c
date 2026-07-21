#include<stdio.h>
int main()
{
  int m[200000],n,i;
  int max,min;

  scanf("%d",&n);
   for(i=0;i<n;i++)
  scanf("%d",&m[i]);

 min = m[0];
 max = m[1]-m[0];
 for(i=1;i<n;i++){

if(max<m[i]-min) 
 max=m[i]-min;

if(min > m[i])
 min=m[i];

}
printf("%d\n",max);

return 0;
}
