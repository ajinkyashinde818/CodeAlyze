#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <functional>
#include <queue>
#include <iostream>
#include <string.h>
#include <iomanip>
#include <algorithm>
#include <functional>
#include <cstdint>
#include <climits>
#include <unordered_set>
#include <sstream>

using namespace std;

#define ll long long int
#define pii pair<int,int>
#define ti3 tuple<ll,ll,ll>

struct BIT
{
    std::vector<int> bit;
    
    BIT(int size) : bit(size, 0){ }
    
    void add(int k, int x) {
        while (k < bit.size()) {
            bit[k] += x;
            k += k &-k;
        }
    }
    int sum(int k) {
        int res = 0;
        while (k > 0) {
            res += bit[k];
            k -= k&-k;
        }
        return res;
    }
};

struct UnionFind {
    vector<int> data;
    
    UnionFind(int size) : data(size, -1) { }
    
    bool unionSet(int x, int y) {
        x = root(x); y = root(y);
        if (x != y)
        {
            if (data[y] < data[x]) swap(x, y);
            data[x] += data[y]; data[y] = x;
        }
        return x != y;
    }
    bool findSet(int x, int y) {
        return root(x) == root(y);
    }
    int root(int x) {
        return data[x] < 0 ? x : data[x] = root(data[x]);
    }
    int size(int x) {
        return -data[root(x)];
    }
};

char a[50][50];
char b[50][50];
int n, m;

bool match(int x, int y)
{
    for(int dy = 0;dy < m;dy++)
    {
        int cy = y + dy;
        for(int dx = 0;dx < m;dx++)
        {
            int cx = x + dx;
            if(a[cy][cx] != b[dy][dx])
            {
                return false;
            }
            
        }
    }
    return true;
}

int main(void)
{
    cin >> n >> m;
    for(int y = 0;y < n;y++)
    {
        for(int x = 0;x < n;x++)
        {
            cin >> a[y][x];
        }
    }
    for(int y = 0;y < m;y++)
    {
        for(int x = 0;x < m;x++)
        {
            cin >> b[y][x];
        }
    }
    for(int y = 0;y < n - m + 1;y++)
    {
        for(int x = 0;x < n - m +1;x++)
        {
            if(match(x, y))
            {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;
    return 0;
}
