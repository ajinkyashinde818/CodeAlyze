#include <bits/stdc++.h>
using namespace std;
int main(void){
    // Your code here!
    string s;
    long long a=0,b=0,c=0,d=1,e=1,f=0,g=0;
    vector<int> u(0);
    cin >> s;
    for (int i=0;i<s.size();i++){
        if (s.at(i)=='.') c++;
        else if (s.at(i)=='(') c++;
        else if (s.at(i)==')') break;
        else {
            if (c>=1) a++;
            if (c==2) b++;
            u.push_back(s.at(i)-'0');
        }
    }
    for (int i=0;i<u.size();i++){
        f+=d*u.at(u.size()-i-1);
        d*=10;
    }
    d=1;
    if (b>0) {for (int i=0;i<u.size()-b;i++){
        f-=d*u.at(u.size()-b-i-1);
        d*=10;
    }
    d=1;
    }
    for (int i=0;i<a;i++){
        d*=10;
    }
    int h=0;
    if (b>0){
    for (int i=0;i<a-b+1;i++){
        if (i==0) h=1;
        else h*=10;
    }
    }
    g=d-h;
    int y=__gcd(f,g);
    f=f/y;g=g/y;
    cout << f << "/" << g << endl;
    
}
