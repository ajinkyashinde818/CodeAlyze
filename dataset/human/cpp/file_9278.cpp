#include<cstdio>
#include<cmath>
#include<string>
#include<iostream>
#include<algorithm>
#include<utility>
#include<vector>
#include<map>
#include<set>
#include<limits>
#include<bitset>
#include<array>
#include<numeric>
#include<iomanip>
#include<functional>

using namespace std;
typedef long long int ll;

#define C cout<<
#define E <<endl

ll n,m,a,b,c,x,y,z,aa[100010],ba[100010];
bool r,ra,rb,rc;
string s,sa,sb,sc;
char ca,cb,cc[1000][1000],cd[1000][1000];
vector<ll> va,vb,vc;

int main(){
    cin>>n>>m;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>cc[i][j];
        }
    }
    
    for(int i=0;i<m;i++){
        for(int j=0;j<m;j++){
            cin>>cd[i][j];
        }
    }
    
    for(int i=0;i<=n-m;i++){
        for(int j=0;j<=n-m;j++){
            r=true;
            for(int bi=0;bi<m;bi++){
                for(int bj=0;bj<m;bj++){
                    r=r and cc[bi+i][bj+j]==cd[bi][bj];
                }
            }
            if(r){
                C "Yes" E;
                return 0;
            }
            
        }
    }
    C "No" E;
}
