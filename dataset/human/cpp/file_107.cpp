#include<iostream>
#include<algorithm>
using namespace std;
int R,G,B,N,L;
long long res;
void Count()
{
	int g=L/G;
	for(int i=0;i<=g;i++)
	{
		int LL=L-i*G;
		if(LL%B==0)
			res++;
	}
	return ;
}
int main()
{
	cin>>R>>G>>B>>N;
	int r=N/R;
	for(int i=0;i<=r;i++)
	{
		L=N-i*R;
		Count();
	}
	cout<<res<<endl;
	return 0;
}
