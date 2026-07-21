#include	<bits/stdc++.h>
using namespace std;

int	main() {
	int N;
	cin >>N;
	vector<long> a(N);
	long Total=0;
	for (int i=0; i<N; i++) {
		cin >>a.at(i);
		Total +=a.at(i);
	}
	long P1=a.at(0);
	long D=abs(Total-P1-P1);
	for (int i=1; i<N-1; i++) {
		P1 +=a.at(i);
		D=min(D, abs(Total-P1-P1));
	}
	cout <<D <<endl;
	return 0;
};
