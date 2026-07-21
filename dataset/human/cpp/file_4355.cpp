#include <bits/stdc++.h>
using namespace std;

const int DIM = 500005;

int arr1[DIM], arr2[DIM], aux[DIM], fth[DIM];

int getroot(int x)
{
    return fth[x] > 0 ? getroot(fth[x]) : x;
}

void unite(int p1, int p2, int &ans)
{
    p1 = getroot(p1),
    p2 = getroot(p2);
    
    if (fth[p1] > fth[p2])
        swap(p1, p2);
    if (p1 != p2)
        fth[p1] += fth[p2], fth[p2] = p1, --ans;
}

int main(void)
{
    int n, k = 0; cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> arr1[i], arr1[0] ^= arr1[i];
    for (int i = 1; i <= n; ++i)
        cin >> arr2[i], arr2[0] ^= arr2[i];
    
    aux[++k] = arr1[0]; aux[++k] = arr2[0];
    for (int i = 1; i <= n; ++i) if (arr1[i] != arr2[i])
        aux[++k] = arr1[i], aux[++k] = arr2[i];
    
    sort(aux + 1, aux + k + 1);
    k = (int) (unique(aux + 1, aux + k + 1) - (aux + 1));
    
    for (int i = 1; i <= k; ++i)
        fth[i] = -1;
    
    int ans = k - 1;
    for (int i = 1; i <= n; ++i) {
        int p1 = (int) (lower_bound(aux + 1, aux + k + 1, arr1[i]) - aux),
            p2 = (int) (lower_bound(aux + 1, aux + k + 1, arr2[i]) - aux);
        
        if (p1 != p2)
            ++ans, unite(p1, p2, ans);
    }
    
    sort(arr1, arr1 + n + 1);
    sort(arr2, arr2 + n + 1);
    
    for (int i = 0; i <= n; ++i)
        if (arr1[i] != arr2[i]) ans = -1;
    
    cout << ans << endl;
    return 0;
}
