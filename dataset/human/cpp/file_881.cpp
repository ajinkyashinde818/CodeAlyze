#include<iostream>
using namespace std;

int main(){
	int R,G,B,N,ans,r,g,b,A;
	double x;
	cin>>R>>G>>B>>N;
	
	for(int i=0;i<=N;i++){	
		r=i;
		for(int j=0;j<=N;j++){
			g=j;
			A=r*R+g*G;
			b=(N-A)/B;
			x=((double)N-(double)A)/(double)B;
			
			if(A<=N&&b==x)
				ans++;
		}
			
	}
	
	
	cout<<ans<<endl;
}
