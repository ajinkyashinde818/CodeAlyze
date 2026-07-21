// Kongo Type

// 素直に実装
// ffffffff = -16777215.9921875

#include<iostream>
#include<bitset>
#include<cmath>
using namespace std;

bitset<32> hexToBin(string hex) {
    bitset<32> bin;
    for(int i=0; i<hex.size(); i++) {
        int dec;
        if(isdigit(hex[i])) dec = hex[i]-'0';
        else dec = hex[i]-'a'+10;
        bitset<32> bits(dec);
        bits <<= (hex.size() - 1 - i)*4;
        bin |= bits;
    }
    return bin;
}

int main()
{
    int Q;
    string s;
    cin>>Q;
    while(Q-->0) {
        cin>>s;
        bool sign;
        int integer=0;
        int decimal=0;
        bitset<32> bin = hexToBin(s);
        int pow;
        sign = bin[31];
        pow = 1;
        for(int i=7; i<31; i++) {
            integer += pow*bin[i];
            pow <<= 1;
        }
        pow = 5000000;
        for(int i=0; i<7; i++) {
            decimal += pow*bin[6-i];
            pow /= 10;
            pow *= 5;
        }
        int digits=7-log10(decimal);
        while((decimal%10==0) && decimal!=0) decimal/=10;
        cout<<(sign?"-":"")<<integer<<".";
        while(digits-->0) cout<<"0";
        cout<<decimal<<endl;
    }
}
