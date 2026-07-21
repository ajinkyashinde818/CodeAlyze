#include<iostream>
using namespace std;

int main(){
	int R,G,B,N,r,g,b,result;
	cin>>R>>G>>B>>N;
	result=0;
	
	for(r=0;r<=N/R;r++){
		for(g=0;g<=(N-r*R)/G;g++){
			if((N-r*R-g*G)%B==0){
				result+=1;
			}
		}
	}
	cout<<result<<endl;
	return 0;
}
