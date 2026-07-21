#include<bits/stdc++.h>
using namespace std;
int n,R,G,B; 
int main(){
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	cin>>R>>G>>B>>n;
	long long res=0;
	for(int r=0;r*R<=n;r++){
		for(int g=0;r*R+g*G<=n;g++){
			int b=n-r*R-g*G;
			if(b==0||b%B==0)
				res++;
		}
	}
	cout<<res<<endl;
	return 0;
}
