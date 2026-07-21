#include <bits/stdc++.h>
using namespace std;




int a[3],k,n,answer;
int main(){
	for(int i=0;i<3;i++){
		cin>>a[i];
	}
	cin>>n;

	sort(a,a+3);
	int k=n/a[0];
	int o=n/a[1];
	for(int i=0;i<=k;i++){
		for(int l=0;l<=o;l++){
			if((n-(a[0]*i)-(a[1]*l))%a[2]==0&&n-(a[0]*i)-(a[1]*l)>=0){
				answer++;
			}
		}
	}
	cout<<answer<<endl;
}
