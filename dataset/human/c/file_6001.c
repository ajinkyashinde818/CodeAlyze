#include<stdio.h>
#define N 200000
int main(){

  int i,j,n;
  int data[N];
  int res,max_i;

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&data[i]);
  }

  max_i=1;
  for(i=2;i<n;i++){
    if(data[max_i]<data[i]){
      max_i=i;
    }
  }
  res=data[1]-data[0];
  for(i=0;i<n-1;i++){
    if(max_i==i){
      max_i++;
      for(j=i+1;j<n;j++){
	if(data[max_i]<data[j]){
	  max_i=j;
	}
      }
      if(res<data[max_i]-data[i]){
	res=data[max_i]-data[i];
      }
    }
    else{ 
      if(res<data[max_i]-data[i]){
	res=data[max_i]-data[i];
      }
    }
  }
  printf("%d\n",res);
  return 0;
}
