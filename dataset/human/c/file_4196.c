#include<stdio.h>
#include<math.h>

long long int fib(int n);

int main(){

  int div = 1000000007;
  int N,M;
  int a[100000];
  int i;
  long long int ans;
  
  scanf("%d %d", &N,&M);

  for(i=0;i<M;i++){
    scanf("%d", &a[i]);
  }

  ans = 1;

  
  if(M==0){
    ans*=fib(N+1);
    printf("%lld\n",ans);
    return 0;
  }

  if(M >=2){
  for(i=1;i<M;i++){
    if(a[i] - a[i-1] == 1){
      ans = 0;
      printf("%lld\n",ans);
      return 0;
    }
  }
  }

  
  if(M != 0){
  ans *= fib(a[0]) ;
  ans = ans % div;
  }

  
  if(M >=2){
  for(i=1;i<M;i++){
    ans *= fib(a[i] - a[i-1] -1) ;
    ans = ans % div;
  }
  }


  
  if(M != 0){
  ans *= fib(N- a[M-1]);
  ans = ans % div;
  //    printf("debug\n");
  }
  
  printf("%lld\n",ans % div);
  
  return 0;

}


long long int fib(int n){
	int i, a, b, c;
	for (i = 0, b = 1, c = 0; i < n; i++) {
		a = b;
		b = c;
		c = a + b;
		c %= 1000000007;
	}
	return c;
}
