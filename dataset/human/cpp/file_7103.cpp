#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>
using namespace std;

template <class T>
struct BIT{
    int size;
    vector<T> data;
    function<T(T, T)> f = [](T a, T b){ return a+b; };
    BIT(){}
    BIT(int n){ init(n); }
    void init(int n){
        size = n;
        data.assign(size+1, 0);
    }

    T sum(int x){
        T res = 0;
        while(x > 0){
            res = f(res, data[x]);
            x -= (x & -x);
        }
        return res;
    }

    T sum(int lft, int rit){
        if(lft == 0) return sum(rit);
        return sum(rit) - sum(lft-1);
    }

    void add(int x, T y){
        if(x <= 0) x = 1;
        while(x <= size){
            data[x] = f(data[x], y);
            x += (x & -x);
        }
    }
};

BIT<int> bit;

int main(void){
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    vector< vector<int> > ax(2, vector<int>(n+1, -1)), bx(2, vector<int>(n+1, -1));
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<n;i++) cin >> b[i];

    for(int i=0;i<n;i++){
        int j = i;
        while(j+1 < n && a[j+1] == a[i]) j++;
        ax[0][a[i]] = i;
        ax[1][a[i]] = j;
        i = j;
    }
    for(int i=0;i<n;i++){
        int j = i;
        while(j+1 < n && b[j+1] == b[i]) j++;
        bx[0][b[i]] = i;
        bx[1][b[i]] = j;
        i = j;
    }

    bit.init(n*3);

    for(int i=0;i<n;i++){
        if(i > 0 && b[i] == b[i-1]) continue;
        int y = b[i];
        if(ax[0][y] == -1) continue;
        int a0 = ax[0][y];
        int a1 = ax[1][y];
        int b0 = bx[0][y];
        int b1 = bx[1][y];
        bit.add(a0-b1, 1);
        bit.add(a1-b0+1, -1);

        bit.add(a0-b1+n, 1);
        bit.add(a1-b0+1+n, -1);
    }

    for(int i=1;i<=n;i++){
        bool flg = true;
        for(int j=i;j<n*3;j+=n){
            if(bit.sum(j) != 0) flg = false;
        }
        if(!flg) continue;
        puts("Yes");
        for(int j=0;j<n;j++) cout << b[(n-i+j)%n] << " "; cout << endl;
        return 0;
    }
    puts("No");

}
