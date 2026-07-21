#include<stdio.h>
#include<string.h> 

	long long int GameCube(long long int a, long long int b) {
  if(a < b) return GameCube(b, a);
  long long int r;
  while ((r=a%b)) {
    a = b;
    b = r;
  }
  return b;
}

int main()
{
	long long int X;
	long long int Y;
	scanf("%ld %ld", &X, &Y);
	printf("%ld", X*Y/GameCube(X, Y));
	
	return 0;
}
