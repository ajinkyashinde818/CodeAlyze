#include<iostream>
#include<vector>

int main(){
	int n;
	long long c;

	std::cin>>n;
	std::cin>>c;

	std::vector<long long> xList(n);
	std::vector<long long> vList(n);

	for(int i=0; i<n; i++)
		std::cin>>xList[i]>>vList[i];

	std::vector<long long> cumSumFwClock(n+1, 0);
	std::vector<long long> cumSumBkClock(n+1, 0);

	for(int i=0; i<n; i++){
		cumSumFwClock[i+1]= cumSumFwClock[i] + vList[i];
		cumSumBkClock[i+1]= cumSumBkClock[i] + vList[n-i-1];
	}

	for(int i=0; i<n; i++){
		cumSumFwClock[i+1]= cumSumFwClock[i+1] - xList[i];
		cumSumBkClock[i+1]= cumSumBkClock[i+1] - (c- xList[n-i-1]);
	}

	std::vector<long long> dpFwClock(n+1, 0);
	std::vector<long long> dpBkClock(n+1, 0);		

	for(int i=1; i<n+1; i++){
		if(dpFwClock[i-1]<cumSumFwClock[i])
			dpFwClock[i]= cumSumFwClock[i];
		else
			dpFwClock[i]= dpFwClock[i-1];

		if(dpBkClock[i-1]<cumSumBkClock[i])
			dpBkClock[i]= cumSumBkClock[i];
		else
			dpBkClock[i]= dpBkClock[i-1];
	}

	for(int i=0; i<n; i++){
		cumSumFwClock[i+1]= cumSumFwClock[i+1] - xList[i];
		cumSumBkClock[i+1]= cumSumBkClock[i+1] - (c- xList[n-i-1]);
	}


	long long ans= 0;

	for(int i=0; i<n+1; i++){
		if(ans< dpFwClock[i] + cumSumBkClock[n-i])
			ans= dpFwClock[i] + cumSumBkClock[n-i];

		if(ans< dpBkClock[i] + cumSumFwClock[n-i])
			ans= dpBkClock[i] + cumSumFwClock[n-i];
	}


	std::cout<<ans<<std::endl;

	return 0;
}
