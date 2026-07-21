#include <stdio.h>

int main(){
  long n,k;
  long a[200000]={0};
  long flag[200000]={0};
  long loop,loopstart,loopend,next;
  long i,j;
  
  scanf("%ld %ld",&n,&k);
  for(i=0;i<n;i++){
    scanf("%ld",&a[i]);
  }
  
  loop=1;
  next=1;
  while(1){
    if(flag[next-1]==0){
	    flag[next-1]=loop;
    	next=a[next-1];
    }else{
      loopend=loop;
      loopstart=flag[next-1];
      break;
    }
    loop++;
  }
  
  if(k>loopstart){
    k=k-loopstart;
    k=k%(loopend-loopstart);
    k=k+loopstart;
  }
  
  next=1;
  for(i=0;i<k;i++){
    next=a[next-1];
  }
  
  /*
  printf("loops:%ld\n",loopstart);
  printf("loope:%ld\n",loopend);
  */
  printf("%ld",next);
}
