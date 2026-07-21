#include <stdio.h>
int main(){
  long i,n,result,tmp,tmp_w,want;
  long a[40]={0};
  
  scanf("%ld",&n);
  
  i=0;
  result=0;
  for(tmp=2;tmp*tmp<=n;tmp++){
    if(n%tmp==0){
      a[i]=tmp;
      i++;
      n=n/tmp;
//    printf("+%ld\n",tmp);
      tmp=1;
    }
  }
  if(n!=1) a[i]=n;
  
  i=0;
  tmp=a[0];
  tmp_w=0;
  want=1;
  while(a[i]!=0){
    if(tmp==a[i]){
      tmp_w++;
      if(tmp_w==want){
        result++;
//        printf(" %ld,%ld\n",tmp,tmp_w);
        want++;
        tmp_w=0;
      }
    } else {
      tmp=a[i];
      tmp_w=0;
      want=2;
      result++;
//      printf(" %ld,1\n",tmp);
    }
    i++;
  }
  
  printf("%ld",result);
}
