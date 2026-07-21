#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>

int main(){
	int n;
	long long ans=INT_MAX;
	std::vector<long long> aList;
	std::vector<long long> aSumList;

	std::cin>>n;
	aList.resize(n);
	aSumList.resize(n, 0);

	for(int i=0; i<n; i++)
		std::cin>>aList[i];

	aSumList[0]= aList[0];
	for(int i=1; i<n; i++)
		aSumList[i]= aSumList[i-1]+aList[i];

	for(int i=0; i<n-1; i++)
		ans= std::min(ans ,std::abs(aSumList[i]- (aSumList[n-1]-aSumList[i])));


	std::cout<<ans<<std::endl;

	return 0;
}
