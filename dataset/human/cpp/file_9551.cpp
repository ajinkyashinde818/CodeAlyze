#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template<class T>
inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}

const ll INF = 1e17;
// https://atcoder.jp/contests/abc143/submissions/8034843

bool checkIndex(int M, int line, int index, vector<string> &vec_A, vector<string> &vec_B)
{
    //cout << line << "," << M << endl;
    for (int i =1; i < M; i++)
    {
      //cout <<  vec_A[line+i] << "\n" << vec_B[i] << "\n" << endl;
      auto hoge = vec_A[line+i].find(vec_B[i], index);
      //cout << index << "," << hoge << endl;
        if (vec_A[line+i].find(vec_B[i], index) != index)
        {
            return false;
        }
    }
    return true;
}

int main() {
    // input
    int N,M;
    cin >> N >> M;

    vector<string> vec_A;
    vector<string> vec_B;
    vec_A.resize(N);
    vec_B.resize(M);
    for (int i=0; i < N; i++) cin >> vec_A.at(i);
    for (int i=0; i < M; i++) cin >> vec_B.at(i);

    // resolve
    for (int i=0; i < N-M+1; i++)
    {
        auto start=0;
        auto index = vec_A[i].find(vec_B[0], start);
        while(index != string::npos)
        {
            if (checkIndex(M, i, index, vec_A, vec_B))
            {
                cout << "Yes" << endl;
                return 0;
            }
            start=index+1;
            index = vec_A[i].find(vec_B[0], start);
          //cout << "index:" << index << endl;
        }
    }
  
    cout << "No" << endl;

    return 0;
}
