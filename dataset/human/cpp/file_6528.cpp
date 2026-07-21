#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<unordered_map>
#include<climits>
#include<cstdlib>
#include<cmath>
#include<string>
#include<iomanip>
#include<bitset>
#include<list>

using namespace std;

#define ll long long int

ll const MOD = 1000000007;
ll const INF = (long long int)1 << 61;

template<typename dataType>
class SegmentTree{
    int dataSize;
    dataType initialVal;
    std::vector<dataType> tree;
    std::function<dataType(dataType,dataType)> addFunc;
    std::function<dataType(dataType,dataType)> extFunc;

    void internalUpdate(int pointedIndex){
        while(pointedIndex > 1){
            pointedIndex >>= 1;
            tree[pointedIndex] = extFunc(tree[pointedIndex*2],tree[pointedIndex*2+1]);
        }
    }

public:

    SegmentTree(int N, dataType init,
                function<dataType(dataType,dataType)> f1 = [](dataType a,dataType b)->dataType{return a+b;},
                function<dataType(dataType,dataType)> f2 = [](dataType a,dataType b)->dataType{return a+b;})
                :initialVal(init),addFunc(f1),extFunc(f2){
                    dataSize = 1;
                    while(dataSize < N){
                        dataSize *= 2;
                    }
                    tree = std::vector<dataType>(dataSize*2,initialVal);
                }

    void initialize(vector<dataType> data){
        for(int i = dataSize; i < dataSize*2 && i - dataSize < data.size(); i++){
            tree[i] = data[i - dataSize];
        }
        for(int i = dataSize - 1; i > 0; i--){
            tree[i] = extFunc(tree[i*2],tree[i*2+1]);
        }
    }

    bool updateQuery(int index,dataType newVal){
        if(index < 1 || index > dataSize){
            return false;
        }
        int pointedIndex = dataSize + index - 1;
        tree[pointedIndex] = newVal;
        internalUpdate(pointedIndex);
        return true;
    }

    bool addQuery(int index,dataType newVal){
        if(index < 1 || index > dataSize){
            return false;
        }
        int pointedIndex = dataSize + index - 1;
        tree[pointedIndex] = addFunc(tree[pointedIndex],newVal);
        internalUpdate(pointedIndex);
        return true;
    }

    dataType getQuery(int leftIndex , int rightIndex){
        if(leftIndex > rightIndex || leftIndex < 1 || rightIndex > dataSize){
            return initialVal;
        }else if(leftIndex == rightIndex){
            return tree[dataSize + leftIndex - 1];
        }

        int leftPointedIndex = dataSize + leftIndex - 1;
        int rightPointedIndex = dataSize + rightIndex - 1;

        dataType leftVal = tree[leftPointedIndex];
        dataType rightVal = tree[rightPointedIndex];
        
        while(true){
            bool wasLeftEven = (leftPointedIndex % 2 == 0);
            bool wasRightEven = (rightPointedIndex % 2 == 0);

            leftPointedIndex >>= 1;
            rightPointedIndex >>= 1;

            if(leftPointedIndex == rightPointedIndex){
                return extFunc(leftVal,rightVal);
            }

            if(wasLeftEven){
                leftVal = extFunc(leftVal,tree[leftPointedIndex*2 + 1]);
            }

            if(!wasRightEven){
                rightVal = extFunc(rightVal,tree[rightPointedIndex*2]);
            }
        }

        return initialVal;
    }
};

ll mypow(ll x,ll n,ll mod = MOD){
    ll ret = 1;
    while(n > 0){
        if(n&1){
            ret = (ret*x)%mod;
        }
        x = (x*x)%mod;
        n >>= 1;
    }
    return ret;
}

ll mygcd(ll a,ll b){
    if(b == 0)return a;
    return mygcd(b,a%b);
}

ll twoPow(ll shiftNum){
    return (1LL << (shiftNum - 1));
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
 
    ll n;
    cin >> n;

    string str;
    cin >> str;

    vector<ll> eq(str.size(),0);

    for(int i = 0; i < str.size(); i++){
        if(i%2 == 0){
            if(str[i] == 'B'){
                eq[i] = 0;
            }else{
                eq[i] = 1;
            }
        }else{
            if(str[i] == 'B'){
                eq[i] = 1;
            }else{
                eq[i] = 0;
            }
        }
    }

    ll cnt = 0;

    ll ans = 1;

    for(int i = 0; i < str.size(); i++){
        if(eq[i] == 0){
            cnt++;
        }else{
            if(cnt < 1){
                cout << 0 << endl;
                return 0;
            }else{
                ans *= cnt;
                ans %= MOD;
                cnt--;
            }
        }
    }

    for(int i = 1; i <= n; i++){
        ans *= (ll)i;
        ans %= MOD;
    }

    if(cnt > 0){
        cout << 0 << endl;
        return 0;
    }

    cout << ans << endl;

    return 0;
}
