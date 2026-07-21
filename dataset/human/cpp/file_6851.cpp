#include <bits/stdc++.h>
using namespace std;
int a[200005], b[200005];
int main(){
    int n;
    scanf("%d" ,&n);
    for(int i=1;i<=n;i++){
        scanf("%d", &a[i]);
    }    
    for(int i=1;i<=n;i++){
        scanf("%d", &b[i]);
    }
    reverse(b+1, b+1+n);
    int l = -1, r = -1;
    for(int i=1;i<=n;i++){
        if(a[i] == b[i]){
            if(l == -1) l = i;
            r = i;
        }
    }
    if(l == -1){
        printf("Yes\n");
        for(int i=1;i<=n;i++){
            printf("%d ", b[i]);
        }
    }
    else{
        vector<int> sw;
        for(int i=1;i<=n;i++){
            if(a[i] != b[i] && b[i] != b[l] && a[i] != b[l]){
                sw.emplace_back(i);
            }
        }
        if(sw.size() >= r-l+1){
            for(int i=l;i<=r;i++){
                swap(b[i], b[sw.back()]);
                sw.pop_back();
            }

            printf("Yes\n");
            for(int i=1;i<=n;i++){
                printf("%d ", b[i]);
            }
        }
        else{
            printf("No\n");       
        }
    }
}
