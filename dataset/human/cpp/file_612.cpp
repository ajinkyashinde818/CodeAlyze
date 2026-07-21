#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

int main()
{
	int R,G,B, N;
	cin>>R>>G>>B>>N;
	int ans = 0;
	for (int r =0 ;r<= N/R;r++){
		int deci = N - r*R;
		for(int g = 0;g<=deci/G;g++){
			if((deci-g*G)%B==0)ans+=1;
		}
	}
	cout<<ans<<endl;
	return 0;
}
