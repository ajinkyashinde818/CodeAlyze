#include <iostream>
#include <stdio.h>
#include <vector>

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    std::vector <std::string> a;
    std::vector <std::string> b;
    std::string s;
    for(int i=0;i<n;i++)
    {
        std::cin>>s;
        a.push_back(s);
    }
    for(int i=0;i<m;i++)
    {
        std::cin>>s;
        b.push_back(s);
    }
    for(int j=0;j<=n-m;j++)
    {
        std::string::size_type pos1 = a[j].find(b[0],0);
        if(pos1!=std::string::npos){
            int num=1;
            if(m==1){
                std::cout<<"Yes"<<"\n";
                    return 0;
            }
            for(int k=1;k<m;k++)
            {
                num++;
                if(num==m){
                    std::cout<<"Yes"<<"\n";
                    return 0;
                }
                std::string::size_type pos2 = a[j+k].find(b[k],pos1);
                if(pos2!=pos1)break;
                
            }
        }
    }
    std::cout<<"No"<<"\n";
    return 0;
}
