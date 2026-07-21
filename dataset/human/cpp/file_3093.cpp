#include<bits/stdc++.h>
using namespace std;
int main(){
	int N;cin>>N;
	vector<long> A(N);
	long count=0,sum=0;
	for(int i=0;i<N;i++){
        cin>>A[i];
		if(A[i]<0){
            A[i]=-A[i];
			count++;
		}sum+=abs(A[i]);
	}if(count%2==0){
		cout<<sum<<endl;
	}else{
		long k=*min_element(A.begin(),A.end());
		cout<<sum-2*k<<endl;
	}
}
