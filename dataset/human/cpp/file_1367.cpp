#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <utility>
#include <math.h>
#include <stdexcept>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cassert>
#include <string.h>

using namespace std;
#define  rep(i,n) for(int i=0;i<n;i++)
#define  rrep(i,n) for(int i=n-1;i>=0;i--)///n-1番目からn回
#define  REP(i,a,b) for(int i=a;i<b;i++) ///a番目からb回
#define  RREP(i,a,b) for(int i=a;i<b;i--)
typedef long long int ll;
typedef vector<ll> vl;
typedef vector<int> vi;
typedef vector<string> vs;



//int arr[N]
////sort(arr,arr +N)

//vector <int> hoge
////sort(hoge.begin(),hoge.end());
///*min_element(hoge.begin(),hoge.end();　最小値　　　最大値はmax_element();

#define Ru(n)  ( ((n)+9)/10*10  ) //切りあげ
#define Rd(n)  ( ((n)-10)/10*10 +10 )	切り捨て

int gcd(int a,int b);
int main() {
	int r,g,b,n,sum=0,ans=0;
	cin>>r>>g>>b>>n;

	for(int i=0;i<=n/r;i++){
		for(int k=0;k<=n/g;k++){
				sum=   i*r + g*k;
				//cout<<sum<<endl;
				if((n-sum)%b==0 &&sum<=n)
					ans++;
			//}
		}
	}
	cout<<ans;
}







int gcd(int a,int b){
	if(b==0) return a;
	return gcd(b,a%b);
}
