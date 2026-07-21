#include<iostream>
#include<math.h>
using namespace std;
int main(){
	int a;
	cin>>a;
	int b[a],c=0,d=pow(10,9);
	for(int i=0;i<a;i++){
		cin>>b[i];
		if(b[i]<0){
			c++;
			b[i]=b[i]*(-1);
		}
		if(d>b[i])
			d=b[i];
	}
	int long long ans=0;
	if(c%2==0){
		for(int i=0;i<a;i++){
			ans+=b[i];
		}
	}
	else{
		for(int i=0;i<a;i++){
			ans+=b[i];
		}
		ans=ans-d*2;
	}
	cout<<ans<<endl;
	return 0;
}
