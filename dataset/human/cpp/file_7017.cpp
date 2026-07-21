#include<stdio.h>
#include<string.h>
#include<math.h>
#include<map>
#include<stack>
#include<set>
#include<queue>
#include<vector>
#include<stdlib.h>

#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cstdlib>

#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
const int maxn=2e5+100;
const int mod=1e9+7;
int n,a[maxn],b[maxn];
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=n;i>=1;i--)
		cin>>b[i];
	for(int i=1;i<=n;i++){
		if(a[i]==b[i]){
			bool flag=0;
			for(int j=1;j<=n;j++){
				if(b[j]!=a[i]&&b[i]!=a[j]){
					swap(b[i],b[j]);
					flag=1;
					break;
				}
			}
			if(!flag){
				cout<<"No";
				return 0;
			}
		}
	}
	cout<<"Yes"<<endl;
	for(int i=1;i<=n;i++) cout<<b[i]<<" ";
	system("pause");
    return 0;
}
