#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int main()
{
	long R,G,B,n,s=0,r,g;
	cin>>R>>G>>B>>n;
	for(r=0;r<=3000;r++)for(g=0;g<=3000;g++)
	{
		if(0<=n-r*R-g*G&&(n-r*R-g*G)%B==0)s++;
	}
	cout<<s<<endl;
}
