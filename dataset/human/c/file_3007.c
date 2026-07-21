#include<stdio.h>
#include<stdlib.h>
int n;
int alllength;
int length;
int distance;
int maxmum=0;
int main(){
  scanf("%d",&alllength);
  scanf("%d",&n);
  int array[n];
  for(int i=0;i<n;i++){
    scanf("%d",&array[i]);
  }
   maxmum=alllength-array[n-1]+array[0];
    for(int i=0;i<(n-1);i++){
      distance=abs(array[i+1]-array[i]);
    	if(maxmum<distance){
          maxmum=distance;
        }
     }
   
  
  length=(alllength-maxmum);
  printf("%d",length);
}
