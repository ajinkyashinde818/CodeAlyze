#include <bits/stdc++.h>
using namespace std;
long int pow107 = (int)pow(10, 9) + 7;

bool comp(pair<int, string> a, pair<int, string> b){
    if(a.first != b.first) return a.first > b.first;
    else return a.second < b.second;
}

long int jou(long int x, long int y){
    long int f = 1;
    for(int i = 0; i < y; ++i){
        f = f * x % pow107;
    }
    return f;
}

bool pn(long int x){
    if(x != 2 && x % 2 == 0)
        return false;
    for(int i = 3; i < x; ++i){
        if(x != i && x % i == 0)
            return false;
    }
    return true;
}

long int factorial(long int n){
    long int f = 1;
    for(long int i = 1; i <= n; ++i){
        f = f * i % pow107;
    }
    return f;
}


int main(){
    int N,M;
 cin >> N >> M;

 const int nmmax=50;
 char A[nmmax][nmmax],B[nmmax][nmmax];


for(int y=0;y<N;++y){
 for(int x=0;x<N;++x){
 cin >> A[y][x];
 }
 }

 for(int y=0;y<M;++y){
 for(int x=0;x<M;++x){
 cin >> B[y][x];
 }
 }

 bool exist=false;

 for(int ly=0;ly<N;++ly){
 for(int lx=0;lx<N;++lx){
 if(ly+M-1>=N or lx+M-1>=N) continue;

 bool match=true;
 for(int y=0;y<M;++y){
 for(int x=0;x<M;++x){
 if(A[ly+y][lx+x]!=B[y][x]) match=false;
 }
 }
 if(match) exist=true;
 }
 }

 if(exist)
 cout << "Yes" << endl;
 else
 cout << "No" << endl;

 return 0;
 }
//   return 0;
