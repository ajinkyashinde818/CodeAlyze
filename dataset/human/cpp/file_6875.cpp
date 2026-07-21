#include <bits/stdc++.h>
using namespace std;

int N,A[200000],B[200000];

int main(){
	cin>>N;
	for(int i=0;i<N;i++){
		cin>>A[i];
	}
	for(int i=0;i<N;i++){
		cin>>B[i];
	}
	reverse(B,B+N);
	int f=0;
	int b=N-1;
	for(int i=0;i<N;i++){
		if(A[i]==B[i]){
			if(B[f]!=A[i]&&A[f]!=B[i]){
				swap(B[f],B[i]);
				f++;
			}
			else{
				swap(B[b],B[i]);
				b--;
			}
		}
	}
	for(int i=0;i<N;i++){
		if(A[i]==B[i]){
			cout<<"No"<<endl;
			return 0;
		}
	}
	cout<<"Yes"<<endl;
	for(int i=0;i<N;i++){
		cout<<B[i];
		if(i!=N-1)cout<<' ';
	}
	cout<<endl;
}
