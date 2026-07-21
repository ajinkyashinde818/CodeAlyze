#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,k,a[N],f[N],b[N],F,le,ri,l,r;
int main(){
	cin>>n;
	for(k=1;k<=n;k++){
		cin>>a[k];
		f[a[k]]++;
	}
	for(k=1;k<=n;k++){
		cin>>b[k];
		f[b[k]]++;
		if(f[b[k]]>n){
		F=1;
		} 
	}
	if(F) cout<<"No"<<endl;
	else
	{
		reverse(b+1,b+n+1);
		for(k=1;k<=n;k++){
			if(a[k]==b[k])F=a[k];
		}
	    
		if(F){ l=n;
			for(k=1;k<=n;k++){
				if(a[k]==F) l=min(l,k);
				if(b[k]==F) l=min(l,k);
			}le=1; ri=n;
			for(k=1;k<=n;k++){
				if(b[k]==F && a[k]==F){
					if(le<l){
					swap(b[k],b[le]);le++;
					}
					else {
						swap(b[k],b[ri]); 
						ri--;
					}
				}
			}
		}
		cout<<"Yes"<<endl;
		for(k=1;k<=n;k++){
			cout<<b[k]<<" ";
		}
	}
}
