#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <algorithm>
#include <string>
#include <sstream>
#include <complex>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include "bits/stdc++.h"
using namespace std;
typedef long long unsigned int ll;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
#define ALL(a)  (a).begin(),(a).end()

int main(void){
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
