#include<iostream>
#include<string>
using namespace std;
int main(){
	int R,G,B,N;
	cin>>R>>G>>B>>N;
	int x=N/R;
	int y=N/G;
	int ans=0;
	for (int i=0;i<x+1;i++){
		for (int j=0;j<y+1;j++){
			if ((N-i*R-j*G)%B==0 && (N-i*R-j*G)>=0){
				ans=ans+1;
			}
		}
	}
	cout<<ans<<endl;
		

	return 0;
}
