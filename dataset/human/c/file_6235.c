#include<stdio.h>
#include<stdlib.h>

int main()
{
  int n;
  int mini;
  int out;
  
  scanf("%d",&n);

  if(n < 2 || 200000 < n){
    exit(0);
  }

  int Rt[n];

  scanf("%d%d",&Rt[0],&Rt[1]);
  
  if(Rt[0] > Rt[1]){
    mini = Rt[1];
  }
  else
    mini = Rt[0];
  
  out = Rt[1] - Rt[0];
  
  for(int i=2; i<n; i++){
    
    scanf("%d",&Rt[i]);

    if(Rt[i] < 1 || 1000000000 < Rt[i]){
      exit(1);
    }
    
     if(Rt[i] < mini){
       if(out < Rt[i] - mini)
	 out = Rt[i] - mini;
      mini = Rt[i];
     } else if(out < Rt[i] - mini){
       out = Rt[i] - mini;
     }
  }
  printf("%d\n",out);
  return 0;
}
