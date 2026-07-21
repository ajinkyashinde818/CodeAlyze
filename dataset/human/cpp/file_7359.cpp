#include<iostream>
#include <bits/stdc++.h>
#include<stdio.h>
#include <stdlib.h>
#include<string>
#include<queue>
#include<algorithm>
#include<math.h>
using namespace std;
	long long int A[200000],ans=0,sunuke,kuma,sum=0;
	int N;
int main(){

	cin>>N;
	for(int i=0;i<N;i++){
		cin>>A[i];
		sum+=A[i];
	}
	if(N==2){
		cout<<labs(A[0]-A[1])<<endl;
		return 0;
	}
	sunuke=A[0];
	kuma=sum-A[0];
	ans=labs(sum-A[0]-A[0]);
	
	for(int i=1;i<N-2;i++){
		sunuke+=A[i];
		kuma-=A[i];
		if(ans>labs(sunuke-kuma)){
			ans=labs(sunuke-kuma);
		}
	}
	cout<<ans<<endl;
}
