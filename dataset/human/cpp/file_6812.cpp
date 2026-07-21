#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
typedef long long ll;
int a[N],b[N],vis1[N],vis2[N],c[N];
int n,f;
int main(){
	scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
    	scanf("%d",&a[i]);
    	
	}
	
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&b[i]);
	
	}
    reverse(b+1,b+1+n);
    vector<int>p,q;
    int cnt=0,val=0;
    for(int i=1;i<=n;i++){
    	if(a[i]!=b[i])continue;
    	cnt++;
    	val=a[i];
    	p.push_back(i);
	}
	for(int i=1;i<=n;i++){
		if(cnt==0)break;
		if(a[i]==b[i])continue;
		if(a[i]!=val&&b[i]!=val){
			cnt--;
			q.push_back(i);
		}
	}
	if(cnt)printf("No\n");
	else{
		for(int i=0;i<q.size();i++)swap(b[p[i]],b[q[i]]);
		printf("Yes\n");
		for(int i=1;i<=n;i++)
		printf("%d ",b[i]);
		printf("\n");
	}
	
	return 0;
}
