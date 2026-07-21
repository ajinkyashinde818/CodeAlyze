#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	int n,m;cin>>n>>m;
	vector<string> a(n);
	for(int i=0;i<n;++i)cin>>a[i];
	vector<string> b(m);
	for(int i=0;i<m;++i)cin>>b[i];

	for(int i=0;i<n-m+1;++i)
	{
		for(int j=0;j<n-m+1;++j)
		{
			bool match=true;
			for(int k=0;k<m;++k)
			{
				
				for(int l=0;l<m;++l)
				{
					//cout<<a[i+k][j+l]<<b[k][l]<<endl;
					if(a[i+k][j+l]!=b[k][l]){
						match=false;
						break;}
				}
			}
			if(match)
				{
					cout<<"Yes"<<endl;
					return 0;
				}
		}	
	}
	cout<<"No"<<endl;
	return 0;
}
