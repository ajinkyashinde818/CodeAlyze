#include<bits/stdc++.h>
using namespace std;
const int INF=1e9;
const int MOD=1e9+7;
template<typename A,size_t N,typename T>
void Fill(A (&array)[N],const T &val)
{
    std::fill( (T*)array,(T*)(array+N),val );
}
int main(void)
{
    int N,R;
    cin >> N >> R;
    if(N>=10)
    {
        cout << R << endl;
    }
    else{
        cout << R+(100*(10-N)) << endl;
    }
}
