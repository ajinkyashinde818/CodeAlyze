#include <bits/stdc++.h>
using namespace std;

string calc(char s){
    if(s == '0') return "0000";
    if(s == '1') return "0001";
    if(s == '2') return "0010";
    if(s == '3') return "0011";
    if(s == '4') return "0100";
    if(s == '5') return "0101";
    if(s == '6') return "0110";
    if(s == '7') return "0111";
    if(s == '8') return "1000";
    if(s == '9') return "1001";
    if(s == 'a') return "1010";
    if(s == 'b') return "1011";
    if(s == 'c') return "1100";
    if(s == 'd') return "1101";
    if(s == 'e') return "1110";
    if(s == 'f') return "1111";
}

int main(){
    int q; cin>>q;
    while(q--){
        string s; cin>>s;
        string t = "";
        for(int i=0; i<8; i++){
            t += calc(s[i]);
        }

        int ans1 = 0;
        int num1 = (1 << 23);
        for(int i=1; i<=24; i++){
            ans1 += (t[i] == '1') * num1;
            num1 /= 2;
        }

        double ans2 = 0.0;
        double num2 = 0.5;
        for(int i=25; i<=31; i++){
            ans2 += (t[i] == '1') * num2;
            num2 /= 2;
        }

        if(t[0] == '1') cout << "-";
        if(ans2 == 0.0){
            cout << ans1 << ".0" << endl;
        }
        else{
            double ans3 = 1. * ans1 + ans2;
            printf("%.20g\n", ans3);
        }
    }
}
