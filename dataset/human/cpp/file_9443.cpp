#include <bits/stdc++.h>
using namespace std;

int main()
{
  	int n,m;
  	cin>>n>>m;
  	vector<string> gt,temp;
  	string str;
	for(int i=0 ; i<n ; ++i)
    {
    	cin>>str;
      	gt.push_back(str);
    }
  	for(int i=0 ; i<m ; ++i)
    {
    	cin>>str;
    	temp.push_back(str);
    }
  	for(int i=0 ; i<n ; ++i)
    {
    	if((n-i)<m)
        break;
      	for(int j=0 ; j<n ; ++j)
        {
        	if((n-j)<m)
            break;
			if(gt[i][j]==temp[0][0])
            {
              	bool different=false;
				for(int o=0 ; o<m ; ++o)
                {
                	for(int p=0; p<m ; ++p)
                    {
                    	if(gt[i+o][j+p]!=temp[o][p])
                        {
                        	different=true;
                          	break;
                        }
                    }
                  	if(different)
                    break;
                }
                if(!different)
                {
                    cout<<"Yes"<<endl;
                    return 0;
                }
            }
        }
    }
	cout<<"No"<<endl;
	return 0;
}
