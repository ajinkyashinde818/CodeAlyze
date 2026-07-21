#include<stdio.h>
#include<math.h>

int main(){
  int n, m;
  long long int x, c[12], a[12][12];
  long long int csum=0, asum[12]={0}, csum_min=1200001;
  // input
  scanf("%d %d %lld",&n,&m,&x);
  for(int i=0; i<n; i++){   
    scanf("%lld",&c[i]);
    for(int j=0; j<m; j++){
      scanf("%lld",&a[i][j]);
    }
  }
//  printf("%d %d %lld",n,m,x);
//  for(int i=0; i<n; i++){   
//    printf("\n%lld ",c[i]);
//    for(int j=0; j<m; j++){
//      printf("%lld ",a[i][j]);
//    }
//  }
  // 
  int comb_max = pow(2, n);
  for(int k=0; k<comb_max; k++){
    csum = 0;
    for(int j=0; j<m; j++)
      asum[j] = 0;
    // 
    for(int i=0; i<n; i++){
      if((k>>i)&1){
        csum += c[i];
        for(int j=0; j<m; j++)
          asum[j] += a[i][j];
      }  
    }
//    printf("\n%lld ",csum);
//    for(int j=0; j<m; j++){
//      printf("%lld ",asum[j]);
//    }
    // 
    int skill_ok=1;
    for(int j=0; j<m; j++){
      if(asum[j]<x){
        skill_ok=0;
      }
    }
    if(skill_ok==1){
      if(csum_min>csum)
        csum_min = csum;
    }
  }
  if(csum_min==1200001)
    printf("-1");
  else
    printf("%lld",csum_min);
  return 0;
}
