#include <iostream>
#include <string>
using namespace std;

int main()
{
	int a,b;
	cin>>a>>b;
	
	char mp1[a][a],mp2[b][b];

	for(int i=0;i<a;i++)
		for(int j=0;j<a;j++)
			cin>>mp1[i][j];
	for(int i=0;i<b;i++)
		for(int j=0;j<b;j++)
			cin>>mp2[i][j];

	for(int i=0;i<=a-b;i++)
		for(int j=0;j<=a-b;j++)
		{
			bool f=1;

			for(int k=0;k<b;k++)
			{
				for(int l=0;l<b;l++)
					if(mp1[k+i][l+j]!=mp2[k][l]) {f=0;break;}
				if(f==0) break;
			}

			if(f==1) {cout<<"Yes";return 0;}
		}

	cout<<"No";
	
	return 0;
}
