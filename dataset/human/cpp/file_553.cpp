#include<bits/stdc++.h>
using namespace std;
int main(){
	int R,G,B,N;cin>>R>>G>>B>>N;
	int sum=0;int temp;
	for(int i=0;i<=N;i=i+R){
		for(int j=0;j<=N;j=j+G){
            temp=N-i-j;
			if(temp%B==0&&temp>=0){
				sum++;
                //cout<<i/R<<" "<<j/G<<endl;
			}
		}
	}cout<<sum<<endl;
}
