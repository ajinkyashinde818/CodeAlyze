#include<bits/stdc++.h>
using namespace std;

int main(){
	int N,i,mnum=0;
	long long minn=pow(10,9)+1;
	//vector<long long> minn;
	cin >> N;
	long long A[N],ans=0;
	for(i=0;i<N;i++){
		cin >> A[i];
	}
	for(i=0;i<N-1;i++){
		if(A[i]<0){
			A[i]=A[i]*-1;
			A[i+1]=A[i+1]*-1;
			//cout << A[i]<<  endl;
		}
		//cout << i << "回目A=" << abs(A[i]) << " minn=" << minn << " mnum=" << mnum << endl;
		if (minn>abs(A[i])){
          minn=A[i];mnum=i;
        }
	}
	if (minn>abs(A[N-1])) mnum=N-1;
		A[mnum]=A[mnum]*-1;
      	A[N-1]=A[N-1]*-1;
  	if (A[N-1]<0){
    	A[N-1]=A[N-1]*-1;
    	A[mnum]=A[mnum]*-1;
    }
	for(i=0;i<N;i++){
		ans+=A[i];
		//cout << A[i] << endl;
	}
	cout << ans << endl;
	return 0;
}
