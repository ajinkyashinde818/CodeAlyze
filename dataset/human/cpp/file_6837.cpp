#include <algorithm>
#include <complex>
#include <cstdlib>
#include <ctime>
#include <time.h>
#include <iomanip>
#include <iostream>
#include <map>
#include <math.h>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
#include <numeric>
#include <limits>
#include <type_traits>
#include <locale>
#include <omp.h>

using namespace std;
#define SAY_YES cout << "YES" << endl;
#define SAY_Yes cout << "Yes" << endl;
#define SAY_NO cout << "NO" << endl;
#define SAY_No cout << "No" << endl;
#define IFYES(TRUE_OR_FALSE)   \
    if (TRUE_OR_FALSE)         \
    {                          \
        cout << "YES" << endl; \
    }                          \
    else                       \
    {                          \
        cout << "NO" << endl;  \
    }
#define IFYes(TRUE_OR_FALSE)   \
    if (TRUE_OR_FALSE)         \
    {                          \
        cout << "Yes" << endl; \
    }                          \
    else                       \
    {                          \
        cout << "No" << endl;  \
    }
#define IFyes(TRUE_OR_FALSE)   \
    if (TRUE_OR_FALSE)         \
    {                          \
        cout << "yes" << endl; \
    }                          \
    else                       \
    {                          \
        cout << "no" << endl;  \
    }
#define DEBUG_OUTPUT_ARRAY(XXX, ONE)                            \
    for (int i = 0; i < (ONE); i++)                             \
    {                                                           \
        cout << "DEBUG: i = " << i << " -> " << XXX[i] << endl; \
    }
#define DEBUG_OUTPUT_ARRAY2(XXX, ONE, TWO)                             \
    for (int i = 0; i < (ONE); i++)                                    \
    {                                                                  \
        cout << "<<< i = " << i << " >>>" << endl;                     \
        for (int j = 0; j < (TWO); j++)                                \
        {                                                              \
            cout << "DEBUG: j = " << j << " -> " << XXX[i][j] << endl; \
        }                                                              \
    }
#define DEBUG_OUTPUT_ARRAY2_BOX(XXX, ONE, TWO) \
    for (int i = 0; i < (ONE); i++)            \
    {                                          \
        cout << i << "  ";                     \
        for (int j = 0; j < (TWO); j++)        \
        {                                      \
            cout << XXX[i][j] << " ";          \
        }                                      \
        cout << endl;                          \
    }

typedef pair<long long int, long long int> pll;
typedef pair<long long int, pll> lpll;

const long long int mod = 1000000007;
const long long int INF = 1e18;
const long double PI=3.14159265358979323; 
//const long long int pl=1000000;

long long int dp[1000050][4]={};
long long int N,res[400200]={},A[200200],B[200200],a,b,c,d,memo;
bool used[2000200]={};
long long int cou[200020]={};
deque<long long int>deq;
long long int l=0;
vector<long long int>NeedChange,CanChange;
int main(){
    cout << fixed << setprecision(18);
    cin>>N;
    for(long long int i = 0; i < N; i++){
        cin>>A[i];
        cou[A[i]]++;
    }
    for(long long int i = 0; i < N; i++){
        cin>>B[i];
        cou[B[i]]++;
        
    }
    sort(B,B+N,greater<long long int>());
    for(long long int i = 1; i <= 200000; i++){
        if(cou[i]>N){cout<<"No"<<endl;return 0;}
    }
    
    cout<<"Yes"<<endl;
    
    for(long long int i = 0; i < N; i++){
        if(A[i]==B[i]){
            memo=A[i];
        }
    }
    for(long long int i = 0; i < N; i++){
        if(A[i]==B[i]){
            NeedChange.push_back(i);
        }else if(A[i]!=memo&&B[i]!=memo){
            CanChange.push_back(i);
        }
        
    }
    for(long long int i = 0; i < NeedChange.size(); i++){
        swap(B[NeedChange[i]],B[CanChange[i]]);
    }
    for(long long int i = 0; i < N; i++){
        cout<<B[i]<<" ";
    }
    cout<<endl;
    
}
