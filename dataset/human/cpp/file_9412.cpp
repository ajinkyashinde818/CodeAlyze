//============================================================================
// Name        : JOI.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <math.h>
#include <stdio.h>
#include <vector>
using namespace std;
typedef long long ll;
int N,M;
char A[51][51];
char B[51][51];
int main(){
	cin>>N>>M;
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			cin>>A[i][j];
		}
	}
	int ans;
	for(int i=0;i<M;i++){
		for(int j=0;j<M;j++){
			cin>>B[i][j];
		}
	}
	for(int i=0;i<N-M+1;i++){
		for(int j=0;j<N-M+1;j++){
			if(A[i][j]==B[0][0]){
				ans=1;
				for(int k=0;k<M;k++){
					for(int v=0;v<M;v++){
						if(A[i+k][j+v]!=B[k][v]){
							ans=0;
						}
					}
				}
				if(ans==1){
					cout<<"Yes"<<endl;
					return 0;
				}
			}
		}
	}
	cout<<"No"<<endl;

	return 0;
}
