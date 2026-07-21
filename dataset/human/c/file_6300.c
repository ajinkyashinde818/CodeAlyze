#include<stdio.h>

int main( ){


  int t[200000],w,i,minv,maxv;
 
  scanf("%d",&w);

  for(i=0;i<w;i++){

    scanf("%d",&t[i]);

  }

  minv=t[0];
  maxv=t[1]-t[0];

  for(i=1;i<w;i++){

    if(maxv<t[i]-minv)maxv=t[i]-minv;
    
    if(minv>t[i]) minv=t[i];

  }
  
   
  printf("%d\n",maxv);

  return 0;

}
