#include <bits/stdc++.h>
using namespace std;
int main(void){
    int n,m;
    cin>>n>>m;
    std::deque<string> A;
    string a;
    for (int i=0;i<n;i++) {
        cin>>a;
        A.emplace_back(a);
    }
    string b;
    std::deque<string> B;
    for (int j=0;j<m;j++) {
        cin>>b;
        B.emplace_back(b);
    }
    int flag=0;
    for (int k=0;k<n;k++) {
        for (int l=0;l<=n-m;l++) {
            string tmp1=A[k].substr(l,m);
            if (tmp1==B[0]) {
                if (m>1) {
                    for (int hoge=1;hoge<m;hoge++) {
                        if (k+hoge<n) {
                            string tmp2=A[k+hoge].substr(l,m);
                            if (tmp2!=B[hoge]) {
                                break;
                            }
                            if (hoge==m-1) {
                                cout<<"Yes"<<endl;
                                flag=1;
                            }
                        } else {
                            break;
                        }
                    }
                } else {
                    cout<<"Yes"<<endl;
                    flag=1;
                }
            }
            if (flag==1) {
                break;
            }
        }
        if (flag==1) {
            break;
        }
    }
    if (flag==0) {
        cout<<"No"<<endl;
    }
}
