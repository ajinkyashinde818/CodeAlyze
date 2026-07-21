#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>

#include <functional>
#include <cassert>

typedef long long ll;
using namespace std;

#define debug(x) cerr << #x << " = " << x << endl;


#define mod 1000000007 //1e9+7(prime number)
#define INF 1000000000 //1e9
#define LLINF 2000000000000000000LL //2e18
#define SIZE 10000

void to_bin(char *s, int *res){

  for(int i=0;i<8;i++){
    int t;
    if('0' <= s[i] && s[i] <= '9' )
      t = s[i]-'0';
    else
      t = s[i]-'a' + 10;
    
    for(int j=3;j>=0;j--){
      res[i*4+j] = t%2;
      t/=2;
    }
  }

}

void calc(){
  char s[12];
  int bin[50];

  scanf("%s",s);

  to_bin(s,bin);

  if(bin[0]==1)
    printf("-");

  ll num = 0;

  for(int i=1;i<=24;i++){
    num = num*2 + bin[i];
  }

  printf("%lld",num);

  num = 0;

  for(int i=25;i<32;i++){
    num = num*2 + bin[i];
  }

  num *= 78125;

  printf(".");
  
  if(num > 0){
    
    char s2[50];
    sprintf(s2,"%07lld",num);

    int max_i = 0;

    for(int i=0;i<7;i++){
      if(s2[i]!='0') max_i = i;
    }
    s2[max_i+1] ='\0';

    printf("%s",s2);
  }else{
    printf("0");
  }
  
  printf("\n");
}

int main(){
  int q;

  scanf("%d",&q);
  
  while(q--){
    //scanf("%d",&n);
    //if(n==0) break;
    calc();
  }
  
  return 0;
}
