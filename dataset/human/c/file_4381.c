#include <stdio.h>
#include <string.h>

int main(void){
 int n;
  int d1[105], d2[105];
  scanf("%d", &n);
  int flag =0;
  for(int i=0;i<n;i++){
    scanf("%d %d", &d1[i], &d2[i]);
    if(i>=2){
    	if(d1[i]==d2[i]){
      		if((d1[i-1]==d2[i-1]) && (d1[i-2]==d2[i-2])){
              printf("Yes");
              return 0;
            }
        }
    }
  }
  printf("No");
  return 0;
      

}
