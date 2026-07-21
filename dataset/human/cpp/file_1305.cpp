#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int R,G,B,N;
int main(){
	cin>>R>>G>>B>>N;
	int sum=0;
	for(int i=0;i<=N/R;i++){
		for(int j=0;j<=N/G;j++){
			int k=N-i*R-j*G;
			if(k>=0 && k%B==0) sum++;
		}
	}
	cout<<sum<<endl;
	return 0;
}
