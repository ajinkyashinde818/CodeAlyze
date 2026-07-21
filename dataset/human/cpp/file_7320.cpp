#include<iostream>

using namespace std;

int main(void)
{
	int n;
	cin >> n;
	long long a[200005];

	long long sum=0;

	for(int i=1;i<=n;i++)
	{
		cin >> a[i-1];
		sum+=a[i-1];
	}

	long long min=abs(sum-a[0]-a[0]);
	long long fi=0;
	long long se=sum;

	for(int i=1;i<=n-1;i++)
	{
		fi+=a[i-1];
		se-=a[i-1];
		long long tmp=abs(fi-se);
		if(tmp<min)
			min=tmp;
	}

	cout << min << endl;
}
