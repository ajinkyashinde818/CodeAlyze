#include<stdio.h>
int main()
{
   int n,i,j,k,s;
   scanf("%d%d%d",&n,&k,&s);
   if(n!=k)
   {
      for(i=1;i<=k;i++)
	  	 printf("%d ",s);
	  if(s==1000000000)
	  {
	  for(i=1;i<n-k;i++)
	  	 printf("%d ",s-10);
	  	 printf("%d",s-10);
}
      else 
      {
      	for(i=1;i<n-k;i++)
      	 printf("%d ",s+1);
	  	 printf("%d",s+1);
	  }
}
   else 
   {
   	for(i=1;i<n;i++)
   	printf("%d ",s);
   	printf("%d",s);
   }
   return 0;
}
