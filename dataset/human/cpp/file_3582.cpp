#include <iostream>
#include <vector>
using namespace std;

typedef long long LL;
int main(int argc, char* argv[])
{
	int N,i;
	cin>>N;
	vector<LL> A(N);
	int pNum=0;
	int mNum=0;
	LL MinAbs=10e9;
	for (i=0;i<N;i++){
		cin>>A[i];
		if (A[i]>=0){
			pNum++;
		}else{
			mNum++;
		}
		LL absV=A[i];
		if (absV<0){
			absV=-absV;
		}
		if (MinAbs>absV){
			MinAbs=absV;
		}
	}
	LL MaxV=0;
	if (mNum%2==0){
		for (i=0;i<N-1;i++){
			if (A[i]<0){
				A[i]=-A[i];
				A[i+1]=-A[i+1];
			}
		}
	}else{
		for (i=0;i<N-1;i++){
			if (A[i]<0){
				if (A[i]==-MinAbs){
					continue;
				}
				A[i]=-A[i];
				A[i+1]=-A[i+1];
			}else if (A[i]>0){
				if (A[i]==MinAbs){
					A[i]=-A[i];
					A[i+1]=-A[i+1];
				}
			}
		}
	}
	for (i=0;i<N;i++){
		MaxV+=A[i];
	}
	cout<<MaxV<<endl;
	return 0;
}
