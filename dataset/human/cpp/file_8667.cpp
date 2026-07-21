#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <numeric>
#include <map>
#include <iomanip>
#include <limits.h>
#include <queue>

using namespace std;    
typedef long long ll;
typedef pair<ll, ll> pll;
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
const bool DEBUG = false;

class Map
{
    public:
    Map(int H, int W){
        height = H;
        width  = W;
        data.resize(H);
        for(int i = 0; i < H; i++) data[i].resize(W);
    }

    bool isIn(int h, int w){
        if(h < 0 || h >= height) return false;
        if(w < 0 || w >= width)  return false;
        return true;
    }

    ll get(int h, int w){
        if( isIn(h, w) ) return data[h][w];
        else return -1; 
    }

    void set(int h, int w, ll val){
        if( isIn(h, w) ){
            data[h][w] = val;
        }
    }

    vector < vector<ll> > data;
    int height;
    int width;

};


int main(){

    int N, M;
    cin >> N >> M;

    Map m1(N , N);
    Map m2(M , M);

    string s;
    for(int i = 0; i < N; i++){
        cin >> s;
        for(int j = 0; j < s.size(); j++){
            if(s[j] == '#') m1.set(i, j, 1);
            else m1.set(i, j, 0);
        }
    }

    for(int i = 0; i < M; i++){
        cin >> s;
        for(int j = 0; j < s.size(); j++){
            if(s[j] == '#') m2.set(i, j, 1);
            else m2.set(i, j, 0);
        }
    }

    bool flag = true;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            flag = true;
            for(int k = 0; k < M; k++){
                if(!flag) break;
                for(int l = 0; l < M; l++){
                    ll col1 = m1.get(i + k, j + l);
                    ll col2 = m2.get(k, l);
                    if(col1 != col2) flag = false;
                    if(!flag) break;
                }
            }
            if(flag){
                cout << "Yes" << endl;
                return 0;
            }
        }
    }

    cout << "No" << endl;

}
