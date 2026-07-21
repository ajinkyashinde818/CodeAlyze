#include <stdio.h>

int main()
{
  long int N;
  scanf("%ld", &N);
  long int D1[N], D2[N];
  long int j;
  for(j=0;j<N;j++){
    scanf("%ld", &D1[j]);
    scanf("%ld", &D2[j]);
  }

  long int i;
  int ans = 0;

  for(i=0;i<N;i++){
    if(D1[i]==D2[i] && D1[i+1]==D2[i+1] && D1[i+2]==D2[i+2] && D1[i]<=6 && D1[i+1]<=6 && D1[i+2]<=6 && 1<=D1[i] && 1<=D1[i+1] &&1<=D1[i+1]){
      ans = 1;
    }
  }

  if(ans==1){
    puts("Yes");
  }else{
    puts("No");
  }

    return 0;
}
