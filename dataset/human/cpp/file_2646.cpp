#include<iostream>
#include<vector>
#include<cmath>
#include<climits>

int main(){
	int n;
	std::vector<int> aList;

	std::cin>>n;
	aList.resize(n);

	for(int i=0; i<n; i++)
		std::cin>>aList[i];

	long long ans= 0;
	bool isZeroExist= false;
	int minAbs= INT_MAX;
	int minusCount= 0;

	for(int i=0; i<n; i++){
		if(aList[i]<0)
			minusCount++;

		if(aList[i]==0)
			isZeroExist=true;

		int varAbs= std::abs(aList[i]);
		minAbs= std::min(minAbs, varAbs);

		ans+= varAbs;
	}

	if(!isZeroExist && minusCount%2== 1)
		ans= ans- (2* minAbs);

	std::cout<< ans<<std::endl;

	return 0;
}
