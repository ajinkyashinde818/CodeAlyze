#include <iostream>
using namespace std;

long long min(long long x,long long y){
	if(x>y){
		return y;
	}else{
		return x;
	}
}

int main(){
	int N;
	long long input,total[200010]={0};
	
	long long answer=1000000000000000000LL;
	
	cin >> N;
	for(int i=1;i<=N;i++){
		cin >> input;
		total[i]=total[i-1]+input;
	}
	
	for(int i=1;i<N;i++){
		answer=min(answer,abs(total[i]-(total[N]-total[i])));
	}
	cout << answer << endl;
	
	return 0;
}
