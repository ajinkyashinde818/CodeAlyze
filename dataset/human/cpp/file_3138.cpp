#include<iostream>
#include<vector>

using namespace std;


int main()
{
	int n;
	cin >> n;
	vector<int> a(n);
	bool flag=false;
	int c=0;
	int mi=100000009;
	long long ans=0;
	for(int i=0;i<n;i++)
	{
		cin >> a[i];
		if(a[i]<0)
			c++;
		if(abs(a[i])<mi)
			mi=abs(a[i]);
		ans+=abs(a[i]);
	}

	if(c%2==1)
		ans-=(mi*2);
	
	cout << ans << endl;
}
