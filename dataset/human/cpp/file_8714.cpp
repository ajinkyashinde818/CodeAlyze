#include <iostream>
#include <string.h>
using namespace std;
char A[51][51];
char B[51][51];
bool isSame(int startI,int startJ,int bWide,int bHigh)
{
	int i,j;
	int bI=0,bJ=0;
	for (i=startI;i<startI+bHigh;i++){
		bJ=0;
		for (j=startJ;j<startJ+bWide;j++){
			if (A[i][j] != B[bI][bJ]){
				return false;
			}
			bJ++;
		}
		bI++;
	}
	return true;
}
int main(int argc, char* argv[])
{
	int N,M;
	cin>>N>>M;
	int i,j;

	for (i=0;i<N;i++){
		cin>>A[i];
	}
	for (i=0;i<M;i++){
		cin>>B[i];
	}
	
	size_t aWide=strlen(A[0]);
	size_t bWide=strlen(B[0]);
	int bHigh=M;
	for (i=0;i<=N-M;i++){
		for (j=0;j<=aWide-bWide;j++){
			if (isSame(i,j,bWide,bHigh)){
				cout<<"Yes"<<endl;
				return 0;
			}
		}
	}

	cout<<"No"<<endl;
	return 0;
}
