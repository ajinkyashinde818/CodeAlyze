#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//const ll mx=1e5;
//bool prime[100009];
//void seive()
//{
//    prime[1]=true;
//    for(int i=2;i*i<=mx;i++){
//        if(prime[i]==false){
//            for(int j=i*i;j<=mx;j+=i) prime[j]=true;
//        }
//    }
//}
int main(){
	ll r,b,g,n;
	cin>>r>>b>>g>>n;
	ll cnt=0;
	vector<ll>v;
	for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            ll total=r*i+b*j;
            //cout<<total<<" ";
            if(total>n)continue;
            v.push_back(total);
        }
	}
	for(auto x: v){
        if((n-x)%g==0)cnt++;
	}
	cout<<cnt<<endl;
}
