#include <iostream>
#include <vector>
using namespace std;
typedef long long LL;
const LL MAX_VAL=1000000000000000000LL;
int main(int argc, char* argv[])
{
	int N;
	cin>>N;
	vector<LL> A(N);
	int i;
	LL S=0;
	for (i=0;i<N;i++){
		cin>>A[i];
		S+=A[i];
	}
	LL x=0;
	LL y=0;
	LL minY_x=MAX_VAL;
	for (i=0;i<N-1;i++){
		x+=A[i];
		y=S-x;
		LL y_x=y-x;
		if (y_x<0){
			y_x=-y_x;
		}
		if (minY_x>y_x){
			minY_x=y_x;
		}
	}

	cout<<minY_x<<endl;
	return 0;
}
