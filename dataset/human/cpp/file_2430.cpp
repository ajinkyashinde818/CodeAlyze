#include<bits/stdc++.h>
using namespace std;
int main(){
    int a;
    cin>>a;
    int b[1000000];
    int c[1000000];
    int d=0;
    long long e=0;
    for(int i=0;i<a;i++){
		cin>>b[i];
		c[i]=abs(b[i]);
	}
	for(int i=0;i<a;i++){
		if(b[i]==0){
			d=0;
			break;
		}
		if(b[i]<0){
			d++;
		}
	}
	sort(c,c+a);
	if(d%2==0){
		for(int i=0;i<a;i++){
			e=e+c[i];
		}
	}
	else{
		for(int i=0;i<a;i++){
			if(i==0){
				e=e-c[i];
			}
			else{
				e=e+c[i];
			}
		}
	}
	cout<<e<<endl;
}
