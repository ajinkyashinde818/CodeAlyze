#include<stdio.h>
#include<string.h>

int main(void){
  int n;
  scanf("%d",&n);

  int d[n+1][2];


  int max = 0 , count = 0;
  for(int i = 0;i < n;i ++){
    scanf("%d %d",&d[i][0],&d[i][1]);
    if(d[i][0] == d[i][1]){
      count ++;
    }
    else if(d[i][0] != d[i][1] || i == n-1){
      if(max < count){
        max = count;
      }
      count = 0;
    }
  }

  if(max < count){
    max = count;
  }

  if(max >= 3){
    printf("Yes\n");
  }

  else{
    printf("No\n");
  }


  return 0;
}
