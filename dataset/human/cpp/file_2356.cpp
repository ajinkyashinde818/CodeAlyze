#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Pair{
	long long int a;
	long long int b;
	Pair(){
		a=0;
		b=0;
	}
	bool operator ()(const Pair x,const Pair y){
		return x.a<y.a;
	}
};
int main(){
	int n;
	cin>>n;
	vector<int>a(n);
	long long int sum=0;
	int min=1e9+1,cnt;
	for(int i=0;i<n;i++) {
		cin>>a[i];
		if(a[i]<0){
			sum-=a[i];
			if(min>-a[i]) min=-a[i];
			cnt++;
		}else{
			sum+=a[i];
			if(min>a[i]) min=a[i];
		}
	}
	if(cnt%2==0){
		cout<<sum<<endl;
	}else{
		cout<<sum-min*2<<endl;
	}




	return 0;
}
