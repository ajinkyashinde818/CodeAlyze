#include<iostream>
#include<vector>

int main()
{
    int n,m,i,j,ni,nj,mi,mj;
    bool ans = false;
    char x;
    std::cin>>n>>m;
    std::cin.ignore();
    std::vector<std::vector<char>>ns(n,std::vector<char>(n));
    std::vector<std::vector<char>>ms(m,std::vector<char>(m));
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            std::cin>>x;
            ns[i][j] = x;
        }
        std::cin.ignore();
    }
    for(i=0;i<m;i++){
        for(j=0;j<m;j++){
            std::cin>>x;
            ms[i][j] = x;
        }
        std::cin.ignore();
    }
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(i<=n-m && j<=n-m){
                int co=0;
                for(mi=0,ni=i;mi<m;mi++,ni++){
                    for(mj=0,nj=j;mj<m;mj++,nj++){
                        if(ns[ni][nj]==ms[mi][mj])co++;
                    }
                }
                if(co==m*m){
                    ans = true;
                }
            }
        }
    }
    (ans)?
    std::cout<<"Yes"<<std::endl:
    std::cout<<"No"<<std::endl;
}
