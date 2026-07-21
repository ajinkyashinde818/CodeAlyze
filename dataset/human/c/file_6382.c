#include <stdio.h>

int Benefit(int,int);

int main() {
  int price;
  int n;
  int max_price = 0;
  int min_price;
  int benefit;
  int max_benefit;
  int i,j;

  scanf("%d",&n);
  //price_array = (int *)malloc(n * sizeof(int));
  scanf("%d",&price);
  min_price = price;
  for(i=1;i<n;i++) {
    scanf("%d",&price);
    benefit = Benefit(min_price,price);
    if(i==1) max_benefit = benefit;
    else if(max_benefit < benefit) {
      max_benefit = benefit;
    }
    if(min_price > price) {
      min_price = price;
    }
    //scanf("%d",&price);
  }

  printf("%d\n",max_benefit);

  return 0;
}

int Benefit(int x,int y) {
  return y-x;
}
