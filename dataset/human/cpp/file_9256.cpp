#include <iostream>
#include <vector>
using namespace std;

int check(int x,int y,vector<string> &A,vector<string> &B,int M){
	int i,j;
		for(i=0;i<M;i++){
			for(j=0;j<M;j++){
				if(A[x+i][j+y]!=B[i][j])return 0;
			}
		}
		return 1;
}
int main(void){
	int N,M;
	cin >> N >> M;
	vector<string> A(N);
	vector<string> B(M);
	int i,j,flag;
	for(i=0;i<N;i++)cin >> A[i];
	for(i=0;i<M;i++)cin >> B[i];
	
	for(i=0;i<=(N-M);i++){
		for(j=0;j<=(N-M);j++){
			flag = check(i,j,A,B,M);
			if(flag==1){
				cout << "Yes";
				return 0;
			}
		}
	}
	cout << "No";
	return 0;
	
}
