#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void){
  char str1[5],str2[100],str3[100],str4[100];
  int N,a[20],b[20],c[20],i,sum;
  
  fgets(str1,sizeof(str1),stdin);
  fgets(str2,sizeof(str2),stdin);
  fgets(str3,sizeof(str3),stdin);
  fgets(str4,sizeof(str4),stdin);
  
  N=atoi(str1);
  a[0]=atoi(strtok(str2," "));
  for(i=1;i<N;i++){
    a[i]=atoi(strtok(NULL," "));
  }
  b[0]=atoi(strtok(str3," "));
  for(i=1;i<N;i++){
    b[i]=atoi(strtok(NULL," "));
  }
  c[0]=atoi(strtok(str4," "));
  for(i=1;i<N-1;i++){
    c[i]=atoi(strtok(NULL," "));
  }
  
  sum=b[a[0]-1];
  for(i=1;i<N;i++){
    sum+=b[a[i]-1];
    if(a[i]==a[i-1]+1){
      sum+=c[a[i-1]-1];
    }
  }
  
  printf("%d\n",sum);
  return 0;
}
