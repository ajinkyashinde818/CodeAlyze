#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <algorithm>
#include <sstream>
#include <cmath>
#include <set>
#include <iomanip>
#include <deque>
#include <stdio.h>
using namespace std;

#define REP(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define RREP(i,n) for(int (i)=(int)(n)-1;i>=0;i--)
#define FILL(Itr,n) fill((Itr).begin(),(Itr).end(),n)
#define REMOVE(Itr,n) (Itr).erase(remove((Itr).begin(),(Itr).end(),n),(Itr).end())
#define UNIQUE(Itr) sort((Itr).begin(),(Itr).end()); (Itr).erase(unique((Itr).begin(),(Itr).end()),(Itr).end())
#define LBOUND(Itr,val) lower_bound((Itr).begin(),(Itr).end(),(val))
#define UBOUND(Itr,val) upper_bound((Itr).begin(),(Itr).end(),(val))
typedef long long ll;
#define MOD 1000000007

int main(){
    
    int N,M; cin>>N>>M;
    vector<string> A(N),B(M);
    REP(i,N)cin>>A[i];
    REP(i,M)cin>>B[i];
    
    for(int i=0;i<=N-M;i++){
        for(int j=0;j<=N-M;j++){
            bool flag=true;
            for(int k=i;k<i+M;k++){
                for(int l=j;l<j+M;l++){
                    if(A[k][l]!=B[k-i][l-j])flag=false;
                }
            }
            if(flag){
                cout<<"Yes"<<endl;
                return 0;
            }
        }
    }
    
    cout<<"No"<<endl;
    
    return 0;
}
