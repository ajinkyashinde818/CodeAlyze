#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <bitset>
#include <stack>
#include <utility>
#include <numeric>
#include <algorithm>
#include <functional>
#include <cctype>
#include <complex>
#include <string>
#include <cstring>
#include <sstream>

using namespace std;

#define all(c) c.begin(),c.end()
#define rep(i,n) for(int i=0;i<(int)n;i++)

typedef long long ll;
typedef complex<double> point;
typedef pair<int,int> pii;

// →↑←↓
const int dx[] = {1,0,-1,0};
const int dy[] = {0,-1,0,1};

const double EPS = 1e-9;

double dot(point a,point b){
    return real(conj(a)*b);
}

double cross(point a,point b){
    return imag(conj(a)*b);
}

// 直線と点との距離
// みけんしょう
double dist_line_and_point(point a1,point a2,point b){
    return abs(cross(a2-a1,b-a1)) / abs(a2-a1);
}

// 線分と点との距離
// みけんしょう
double dist_linesegment_and_point(point a1,point a2,point b){
    if(dot(a2-a1,b-a1) < EPS) return abs(b-a1);
    if(dot(a1-a2,b-a2) < EPS) return abs(b-a2);
    return dist_line_and_point(a1,a2,b);
}


// 円と線分の交差判定
bool is_cross_linesegment_and_circle(point c,double r,point a1,point a2){
    return (dist_linesegment_and_point(a1,a2,c) < r+EPS and
             (r < abs(c-a1) + EPS or r < abs(c-a2) + EPS));
}

int main(){
    while(true){
        int n;
        cin >> n;
        if(n == 0) break;
        vector<pair<point,double> > cs;
        for(int i=0;i<n;i++){
            point p;double c;
            cin >> p.real() >> p.imag() >> c;
            cs.push_back(make_pair(p,c));
        }
        int m;
        cin >> m;
        for(int i=0;i<m;i++){
            point a,b;
            cin >> a.real() >> a.imag() >> b.real() >> b.imag();
            bool safe = false;
            for(int j=0;j<n;j++){
                if(is_cross_linesegment_and_circle(cs[j].first,cs[j].second,a,b)){
                    safe = true;
                }
            }
            if(safe){
                cout << "Safe" << endl;
            }else{
                cout << "Danger" << endl;
            }
        }
    }
    return 0;
}
