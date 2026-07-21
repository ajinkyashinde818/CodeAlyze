#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <utility>
#include <queue>
#include <set>
#include <map>
#include <deque>
#include <iomanip>
#include <cstdio>

using namespace std;
typedef  long long ll;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<VI> VVI;
#define  MP make_pair
#define  PB push_back
#define inf  1000000007
#define rep(i,n) for(int i=0;i<(int)(n);++i)

int main(){
    int n;
    cin >> n;
    int p = -1;
    int s = 0;
    for(int i=1;i<=1000;i++){
        s +=i;
        if(s==n){
            p = i;
            break;
        }
    }
    if(p==-1){
        cout << "No" << endl;
    }else{
        cout << "Yes" << endl;
        cout << p+1 << endl;
        cout << p << " ";
        for(int j=1;j<=p;j++){
            cout << j;
            if(j!=p){
                cout << " ";
            }
        }
        cout << endl;
        for(int i=1;i<=p;i++){
            cout << p << " ";
            int zz = 0;
            for(int j=0;j<p;j++){
                if(j==0){
                    cout << i;
                    zz = i;
                }else{
                    if(j<=i){
                        if(j==i){
                            zz += p-j+1;
                        }else{
                            zz += p-j;
                        } 
                        cout << zz;
                    }else{
                        zz++;
                        cout << zz;
                    }
                }
                if(j!=p-1)cout << " ";
            }
            cout << endl;
        }
    }
    return 0;
}
