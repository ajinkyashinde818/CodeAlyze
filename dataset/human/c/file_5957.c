#include <stdio.h>

int main()
{
  int n,i,j,max,min,ori[200000];
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&ori[i]);
  }
  max=-1000000000;
  min=ori[0];

  for(j=1;j<n;j++){
    if(max<ori[j]-min) max=ori[j]-min;
    if(min>ori[j]) min=ori[j];
  }

  printf("%d\n",max);

  return 0;
}
