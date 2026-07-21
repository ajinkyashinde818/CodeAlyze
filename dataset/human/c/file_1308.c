#include <stdio.h>
int main(){
  int n,m,a,b;
  scanf("%d%d",&n,&m);
  int boat[200010] = {};
  for(int i=0; i<m; i++){
    scanf("%d%d",&a,&b);
    if(a == 1){
      if(boat[b]>0){
	printf("POSSIBLE");
	return 0;
      }
      boat[b]++;
    }
    if(b == n){
      if(boat[a]>0){
	printf("POSSIBLE");
	return 0;
      }
      boat[a]++;
    }
  }
  printf("IMPOSSIBLE");
  return 0;
}
