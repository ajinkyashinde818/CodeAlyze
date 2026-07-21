#include<cstdio>
#include<vector>
std::vector<int>g[100005];

int main(){
    int n;
    scanf("%d",&n);
    int m = 2*n, find = -1;
    for(int i = 1; i <= m; i++){
        if(m%i==0){
            int j = m/i;
            if(j==i-1){
                find = i;
                break;
            }
        }
    }
    if(find==-1) printf("No\n");
    else{
        printf("Yes\n%d\n",find);
        int cur = 0;
        for(int i = 1; i <= find; i++){
            for(int j = i+1; j <= find; j++){
                cur++;
                g[i].push_back(cur);
                g[j].push_back(cur);
            }
        }
        for(int i = 1; i <= find; i++){
            printf("%d ",(int)g[i].size());
            for(int j = 0; j < (int)g[i].size(); j++) printf("%d ",g[i][j]);
            printf("\n");
        }
    }
    return 0;
}
