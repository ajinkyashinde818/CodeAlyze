#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
const int maxn = 1e5 + 5 ;
int n , r ;
char s[maxn] ;
int main()
{
	scanf("%d%d" , &n , &r) ;
	if(n >= 10)  printf("%d\n" , r) ;
	else  printf("%d\n" , r + 100 * (10 - n)) ;
    return 0 ;
}
