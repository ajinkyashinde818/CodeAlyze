#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<long long> convert2num(vector<string> A);
bool is_contained(int M, int dx, int dy, const vector<long long> &A, const vector<long long> &B);

int main() {
    int N, M;
    cin >> N >> M;
    vector<string> A(N, "");
    vector<string> B(M, "");
    for (auto & s : A) cin >> s;
    for (auto & s : B) cin >> s;
    auto A01 = convert2num(A);
    auto B01 = convert2num(B);
    for (int dx = 0; dx <= N - M; ++dx){
        for (int dy = 0; dy <= N - M; ++dy){
            if (is_contained(M, dx, dy, A01, B01)){
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;
    return 0;
}

vector<long long> convert2num(vector<string> A){
    vector<long long> A01;
    for (const auto &s : A){
        long long val = 0;
        for (const auto c : s){
            val <<= 1;
            if (c == '#') ++val;
        }
        A01.push_back(val);
    }
    return A01;
}

bool is_contained(int M, int dx, int dy, const vector<long long> &A, const vector<long long> &B){
    long long mask = (1LL << (M + dy)) - 1LL;
    for (const auto b : B){
        if (b != ((A[dx++] & mask) >> dy)) return false;
    }
    return true;
}
