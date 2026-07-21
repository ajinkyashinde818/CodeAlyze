#include <stdio.h>
int main()
{
  int z[106],n,b,i,ch,h;
  scanf("%d %d",&n,&b);
  for(i=0;i<n;i++){
    scanf("%d",&z[i]);
  }
  for(i=1;i<=b;i++){
    h=0;
    while(1){
      if(h==n-1)break;
      if(z[h]%i>z[h+1]%i){
	ch=z[h];
	z[h]=z[h+1];
	z[h+1]=ch;
	h++;
      }else h++;
    }
  }
  for(i=0;i<n;i++)printf("%d\n",z[i]);
  return 0;
}
