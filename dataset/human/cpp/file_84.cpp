#include<bits/stdc++.h>
using namespace std;
int main(){
	int a,b,c,d;
	cin>>a>>b>>c>>d;
	long long cnt = 0;
	for(int i = 0;i*a<=d;i++){
		int x = i*a;
		for(int j=0;j*b<=(d-x);j++){
			int y = j*b;
			if((d-x-y)%c==0){
				cnt++;
				//cout<<i<<" "<<j<<" "<<(d-x-y)/c<<endl;
			}
			}
		}
		cout<<cnt<<endl;
}
