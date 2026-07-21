#include <iostream>
#include <map>
using namespace std;

int main(){
    int N;
    string S;
    map<char, long long> m;
    cin >> N >> S;
    for(const auto &c : S){
        if(m.find(c) == m.end()){
            m[c] = 1;
        }else{
            m[c]++;
        }
    }
    long long x = 1;
    for(auto itr = m.begin(); itr!=m.end(); itr++){
        x *= (itr->second+1)%(1000000000+7);
        x %= 1000000000+7;
    }
    cout << (x-1);
    return EXIT_SUCCESS;
}
