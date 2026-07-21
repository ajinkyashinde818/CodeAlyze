#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int a[200000], b[200000];
int main()
{
    int n;
    cin >> n;
    for(int i=0; i<n; ++i)cin >> a[i];
    for(int i=0; i<n; ++i)cin >> b[i];
    vector<int> ab(2*n);
    for(int i=0; i<n; ++i)ab[i]= a[i];
    for(int i=0; i<n; ++i)ab[n+i]= b[i];
    sort(ab.begin(), ab.end());
    int count = 1, max_count = 1;
    for(int i=1; i<2*n; ++i){
        if(ab[i] == ab[i-1]){
            count += 1;
            max_count = max(count, max_count);
        }else{
            count = 1;
        }
    }
    // 過半数が同じならダメ（鳩ノ巣原理）
    if (max_count > n){
        cout << "No";
        return 0;
    }
    // 逆順にソートするとたかだか連続した1か所だけ被る。この値を c とする
    sort(b, b+n, [](int x, int y){return x>y;});
    int c = -1;
    for(int i=0; i<n; ++i){
        if(a[i]==b[i]){
            c = a[i];
            break;
        }
    }
    if (c>=0){
        // cがいるところどうしが当たらないようにする
        int al=-1, ar=-1, bl=-1, br=-1;
        for(int i=0; i<n; ++i){
            if (a[i]==c){
                if(al==-1){
                    al=i;
                }
            }else{
                if(al>=0 && ar==-1){
                    ar=i;
                }
            }
            if (b[i]==c){
                if(bl==-1){
                    bl=i;
                }
            }else{
                if(bl>=0 && br==-1){
                    br=i;
                }
            }
        }
        int l = max(al, bl), r = min(ar, br);
        int ll = min(al, bl), rr = max(ar, br);
        int j = 0;
        for(int i=l; i<r; ++i){
            if(j == ll)j=rr;
            int tmp=b[i];
            b[i]=b[j];
            b[j]=tmp;
            j+=1;
        }
    }
    cout << "Yes" << endl;
    for(int i=0; i<n-1; ++i)cout << b[i] << " ";
    cout << b[n-1] << endl;
    return 0;
}
