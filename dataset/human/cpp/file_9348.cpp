#include <iostream>
using namespace std;

int N,M;
string A[51]={},B[51]={};

int search(int x,int y){
	
	for(int i=0;i<M;i++){
		for(int k=0;k<M;k++){
			if(A[i+x][k+y]!=B[i][k]){
				return 0;
			}
		}
	}
	
	return 1;
	
}

int main(){
	int answer = -1;

	cin >> N >> M;
	
	for(int i=0;i<N;i++){
		cin >> A[i];
	}
	for(int i=0;i<M;i++){
		cin >> B[i];
	}
	
	for(int i=0;i<N-M;i++){
		for(int k=0;k<N-M;k++){
			answer=max(answer,search(i,k));
		}
	}
	
	if(answer){
		cout << "Yes" << endl;
	}else{
		cout << "No" << endl;
	}
	
	
	return 0;
}
