#include <iostream>
#include <vector>
#include <math.h>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
#include <regex>

using namespace std;

using ull = unsigned long long;
using pii = pair<int,int>;
using vi = vector<int>;
using vs = vector<string>;
using vull = vector<ull>;
using vpii = vector<pii>;

#define fi first
#define se second
#define mp make_pair
#define pb push_back

#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define rFOR(i,a,b) for(int i=(b);i>=(a);i--)
#define SORT(a) sort((a).begin(),(a).end());
#define rSORT(a) sort((a).rbegin(),(a).rend());
#define yn(a) cout <<((a)?"yes":"no")<<endl;
#define Yn(a) cout <<((a)?"Yes":"No")<<endl;
#define YN(a) cout <<((a)?"YES":"NO")<<endl;

//sankou
//vvi = vector<vector<int>>(20, vector<int>(10, 0));

int isP(int n) {
    if(n<=1) return 0;
    FOR(i,2,(int)sqrt(n)) {
        if(n%i==0) return 0;
    }
    return 1;
}

int main() {
    
    int N,M;
    cin >>N>>M;
    vs A(N),B(M);
    string AA="",BB="";
    FOR(i,0,N-1) {
        cin >>A[i];
        FOR(j,0,N-1) {
            if(A[i][j]=='.') A[i][j]='a';
        }
        AA+=A[i];
    }
    FOR(i,0,M-1) {
        cin >>B[i];
        FOR(j,0,N-1) {
            if(B[i][j]=='.') B[i][j]='a';
        }
        BB+=B[i];
        if(i!=(M-1)) {
            FOR(j,1,N) {
                BB+=".";
            }
        }
    }
    Yn(regex_search(AA, regex(BB)));

    return 0;
}
