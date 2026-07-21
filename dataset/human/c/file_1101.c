#include <stdio.h>
#include <string.h>

int mcxi_int(const char mcxi[])
{
  int i,sum=0,p=1;

  for(i=0;mcxi[i];i++){
    if(mcxi[i]=='m'){
      sum+=p*1000; p=1;
    } else if(mcxi[i]=='c'){
      sum+=p*100; p=1;
    } else if(mcxi[i]=='x'){
      sum+=p*10; p=1;
    } else if(mcxi[i]=='i'){
      sum+=p; p=1;
    } else {
      p=mcxi[i]-'0';
    }
  }
  
  return sum;
}

int main(void)
{
  int n,i,j,num;
  char mcxi[]="mcxi";

  scanf("%d", &n);
  for(i=0;i<n;i++){
    char mcxi1[9],mcxi2[9];
    scanf("%s %s", mcxi1, mcxi2);
    num=mcxi_int(mcxi1)+mcxi_int(mcxi2);
    for(j=num;;){
      if(j/1000>1) printf("%d", j/1000);
      if(j/1000) printf("m");
      j%=1000;
      if(j/100>1) printf("%d", j/100);
      if(j/100) printf("c");
      j%=100;
      if(j/10>1) printf("%d", j/10);
      if(j/10) printf("x");
      j%=10;
      if(j>1) printf("%d", j);
      if(j) printf("i");
      break;
    }
    printf("\n");
  }

  return 0;
}
