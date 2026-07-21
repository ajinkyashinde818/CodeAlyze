#include<iostream>
#include<string>
#include<algorithm>
#include<bits/stdc++.h>
 
using namespace std;
 
 int main(void){
     int N,M;
     cin >> N >> M;
     char A[N+10][N+10],B[M+10][M+10];
     for(int i=0; i<N; i++){
         for(int j=0; j<N; j++){
             cin >> A[i][j];
         }
     }for(int i=0; i<M; i++){
         for(int j=0; j<M; j++){
             cin >> B[i][j];
         }
     }
     bool ex=false;
     for(int i=0; i<N; i++){
         for(int j=0; j<N; j++){
             if(i+M-1>=N || j+M-1>=N) continue;

             bool ma=true;
             for(int y=0; y<M; y++){
                 for(int x=0; x<M; x++){
                     if(A[i+y][j+x]!=B[x][y]){
                         ma = false;
                     }
                 }
             }
             if(ma) ex=true;
         }
     }
    if(ex) cout << "Yes" << endl;
    else cout << "No" << endl;
 }
