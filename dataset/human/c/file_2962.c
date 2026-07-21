#include <stdio.h>

int nn[3];
void print3n(){
  printf("%d %d %d\n", nn[0], nn[1], nn[2]);
  return;
}

int cmbNKS(int k, int sum, int num){
  static int cmb[3][7500] = {0};
  if(num==0){
    if(sum==0){
      return 1;
    }else{
      return 0;
    }
  }else if(num<0 || sum<0){
    return 0;
  }
  if(cmb[num-1][sum-1] != 0) return cmb[num-1][sum-1];
  if(k*num < sum){
    return -1;
  }
  
  int i=k, ans=0, n;
  while(i>=0){
    if((n = cmbNKS(k, sum-i, num-1)) == -1) break;
    ans += n;
    i--;
  }

  cmb[num-1][sum-1] = ans;
  return ans;
}

int main()
{
  int k, s;
  
  scanf("%d%d", &k, &s);
  
  printf("%d", cmbNKS(k, s, 3));
  return 0;
}
