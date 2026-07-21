#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> P;

ll gcd(ll a, ll b){
    if(b>a) return gcd(b,a);
    if(a%b == 0) return b;
    return gcd(b,a%b);
}

ll ctoi(char c){ return c-'0';}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    string s; cin >> s;

    bool f = true;
    if(s[s.size()-1] == ')') f = false;

    ll a,b;

    if(f){
        a = 1;
        b = ctoi(s[0]);
        bool d = false;
        for (int i = 1;i < s.size();i++){
            if(s[i] == '.'){ i++; d = true;}
            if(d) a *= 10;
            b = b*10+ctoi(s[i]);
        }
    }else{
        int t1 = 0;
        int t2 = 0;
        int ten = 1;
        int t3 = 1;
        bool d = false;
        t1 = t2 = ctoi(s[0]);
        for (int i = 1;i < s.size();i++){
            if(s[i] == '.') {i++; d = true;}
            if(s[i] == '('){
                i++;
                t2 = t1;
                for (;i < s.size()-1;i++){
                    t2 = t2*10+ctoi(s[i]);
                    ten *= 10;
                }
                break;
            }
            t1 = t1*10+ctoi(s[i]);
            if(d){
                t3 *= 10;
                ten *= 10;
            }
        }
        a = ten-t3;
        b = t2-t1;
    }

    ll a2 = a/gcd(a,b);
    ll b2 = b/gcd(a,b);

    cout << b2 << '/' << a2 << endl;
    

    return 0;

}
