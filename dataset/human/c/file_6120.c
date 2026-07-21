/*
利益が出たら（最小値が更新された時点で）、利益max-minをprof[]に入れおき、
prof[]の中で最大のものを最終的な答えとする。
（入力値が２つだった場合は少し挙動が違うので、例外としてある）
 */


#include<stdio.h>
int main(){
  int max=-1000000000,tmp=-1000000000,min=1000000000,n,i,j=0,a[200000],prof[100000];
    
  scanf("%d",&n);
    
  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
  }
    
  if(n==2){
       
    prof[0]=a[1]-a[0];
    j++;
        
  }else{
        
    for(i=0;i<n;i++){
        
      if(a[i]>max){
	max=a[i];
      }
        
      if(a[i]<min){
            
	prof[j]=max-min;
	j++;
	min=a[i];
	max=-1000000000;
      }
    }
    
    prof[j]=max-min;
    j++;
  }
    
  for(i=0;i<j;i++){
    if(prof[i]>tmp)tmp=prof[i];
  }
  printf("%d\n",tmp);
    
}
