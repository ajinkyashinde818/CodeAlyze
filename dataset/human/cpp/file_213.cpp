#include<iostream>

using namespace std;

int main(){
	int R,G,B,N;
	cin>>R>>G>>B>>N;
	int count=0;
	for(int r=0;r<=N/R;r++){
		for(int g=0;g<=(N-r*R)/G;g++){
			int b=(N-r*R-g*G)/B;
			if(r*R+g*G+b*B==N) count++;
		}
	}
	cout<<count;
}
