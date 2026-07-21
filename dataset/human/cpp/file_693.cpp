#include <bits/stdc++.h>
using namespace std;

int main()
{
	int R,G,B,n;
	cin>>R>>G>>B>>n;
	
	int sum=0;
	for(int i=0;i<=n;i++)
		for(int j=0;j<=n;j++)		//双重循环 
		{
			int k=n-i*R-j*G; 
			if(k%B==0 && k>=0)
				sum++;
		}
				
	
	cout<<sum<<endl;
	return 0;
}
