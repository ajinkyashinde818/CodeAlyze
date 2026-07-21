#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
void fastIO(){
  ios_base::sync_with_stdio(0); cin.tie(0);
}

ll absll(ll a,ll b){
	if(a-b<0){
		return -1*(a-b);
	}else{
		return a-b;
	}
}
ll minll(ll a,ll b){
	if(a>b){
		return b;
	}else{
		return a;
	}
}
int main(){
  fastIO();
  int n;
  cin>>n;
  vector<int>cards(n);
  ll sum1=0,sum2=0;
  for(int i=0;i<n;i++){
  	cin>>cards[i];
  	sum1+=cards[i];
  }
  ll mini = 1e15;
  for(int i=0;i<n-1;i++){
  	sum1-=cards[i];
  	sum2+=cards[i];
  	mini=minll(mini,absll(sum1,sum2));
  }
  cout<<mini<<endl;
}
