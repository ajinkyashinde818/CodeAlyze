#include<stdio.h>
#include<stdbool.h>


int findTown(int V, long K, int adj[])
{
    bool cycle = 0;
    int s = 1, path[V+1], in_path[V+1] = {0}, len = 0;
    long K_cpy = K;
    
    while(K_cpy-- && !cycle)
    {
        if(in_path[s])
            cycle = 1;
        else
        {
            path[++len] = s;
            in_path[s] = len;
            s = adj[s];   
        }
    }
    
    if(cycle)
    {
        int cyc_start = in_path[s];
        K -= (cyc_start - 1);
        int cyc_len = len - cyc_start + 1;
        int node_in_cyc = K % cyc_len;
        return path[cyc_start + node_in_cyc];    
    }
    else
        return s;
}
int main()
{
    int n, ans;
    long k;
    scanf("%d %ld", &n, &k);
    
    int edges[n + 1];
    for(int i = 1 ; i <= n ; i++)
        scanf("%d",&edges[i]);
    
    ans = findTown(n, k, edges);
    
    printf("%d",ans);
}
