#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

const int N=100000,mod=1000000007;

int add(int a,int b,int p=mod){return a+b>=p?a+b-p:a+b;}
int sub(int a,int b,int p=mod){return a-b<0?a-b+p:a-b;}
int mul(int a,int b,int p=mod){return (LL)a*b%p;}
void sadd(int &a,int b,int p=mod){a=add(a,b,p);}
void ssub(int &a,int b,int p=mod){a=sub(a,b,p);}
void smul(int &a,int b,int p=mod){a=mul(a,b,p);}

int n;
char s[N*2+9];

void into(){
  scanf("%d%s",&n,s+1);
}

int ans;

void Get_ans(){
  int now=0;
  ans=1;
  for (int i=1;i<=n<<1;++i){
	(now&1)==(s[i]=='B')?(smul(ans,now),--now):++now;
	if (now<0) {ans=0;return;}
  }
  if (now) ans=0;
  for (int i=1;i<=n;++i) smul(ans,i);
}

void work(){
  Get_ans();
}

void outo(){
  printf("%d\n",ans);
}

int main(){
  into();
  work();
  outo();
  return 0;
}
