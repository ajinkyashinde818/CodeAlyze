#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
#include <cmath>
#include <queue>
#include <stack>
#include <bitset>
#include <map>
#include <string>
#include <utility>

#define repd(i,a,b) for(ll i=(a);i<(b);i++)
#define rep(i,n) repd(i,0,n)
typedef long long ll;

using namespace std;

int inputValue();
void inputArray(int*,int);
void inputVector(vector<int>*,int);
template <typename T>
void output(T,int);
int gcd(int a,int b);

int main(){
	//source
	int n;
	cin >> n;
	int a[n];
	rep(i,n){
		cin >> a[i];
	}
	sort(a,a+n);
	ll ans=0;
	int  num_minus=lower_bound(a,a+n,1)-a;
	if(num_minus%2==0){
		rep(i,n){
			ans+=abs(a[i]);
		}
	}else if(num_minus!=n){
		ll ans1=0,ans2=0;
		rep(i,n){
			if(i<num_minus-1){
				ans1+=a[i]*(-1);
			}else{
				ans1+=a[i];
			}

			if(i<num_minus+1){
				ans2+=a[i]*(-1);
			}else{
				ans2+=a[i];
			}
		}

		ans=max(ans1,ans2);
	}else{
		rep(i,n){
			if(i!=n-1){
				ans+=abs(a[i]);
			}else{
				ans+=a[i];
			}
		}
	}

	cout <<  ans << endl;
	return 0;
}

int inputValue(){
	int a;
	cin >> a;
	return a;
}

void inputArray(int *p,int a){
	rep(i,a){
		cin >> p[i];
	}
}

void inputVector(vector<int> *p,int a){
	rep(i,a){
		int input;
		cin >> input;
		p -> push_back(input);
	}
}

template<typename T>
void output(T a,int precision){
	if(precision > 0){
		cout << setprecision(precision) << a << "\n";
	}else{
		cout << a << "\n";
	}
}

int gcd(int a,int b){
	if(b>a){
		int temp=a;
		a=b;
		b=temp;
	}
	if(b==0){
		return a;
	}
	return (b,b%a);
}
