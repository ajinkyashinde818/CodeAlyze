#include<iostream>
#include<algorithm>
using namespace std;
int N;
long A[1<<17];
main()
{
	cin>>N;
	for(int i=0;i<N;i++)cin>>A[i];
	sort(A,A+N);
	for(int i=0;i+1<N;i+=2)
	{
		if(A[i]+A[i+1]<0)
		{
			A[i]*=-1;
			A[i+1]*=-1;
		}
	}
	long ans=0;
	for(int i=0;i<N;i++)ans+=A[i];
	cout<<ans<<endl;
}
