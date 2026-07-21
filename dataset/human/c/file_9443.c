#include <stdio.h>
int main(){
  int N,D,X;
  scanf("%d",&N);
  int A[N],ans=0;
  scanf("%d %d",&D,&X);
  for(int i=0;i<N;i++){
    scanf("%d",&A[i]);
    ans+=1;
    for(int j=1;j<D;j++){
      int aa=j*A[i]+1;
      if(aa>D)break;
      ans+=1;
    }
  }
  printf("%d\n",ans+X);
}
