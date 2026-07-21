#include <iostream>
using namespace std;

int main(){
    int n,m;
    cin >> n >> m;
   char ndata[50][50];
    char mdata[50][50];
    string result;

    for (int y = 0; y< n; y++){
        for (int x = 0; x < n; x++)
        {
            cin >> ndata[y][x];
        }        
    }

     for (int y = 0; y< m; y++){
        for (int x = 0; x < m; x++)
        {
            cin >>mdata[y][x];
        }        
    }

    bool exist = false;
    for (int ly = 0; ly < n; ly++){
     for (int lx = 0; lx < n; lx++){
            if (ly + m-1 >= n or lx + m-1 > n)continue;

         bool match = true;

        for (int y = 0; y < m; y++){
            for (int x = 0; x < m; x++) {
                if (ndata[ly+y][lx+x] != mdata[y][x])match = false;
            }
        }

        if (match)exist = true;    
      }    
    }

    result = (exist)? "Yes" : "No";
    cout << result <<endl; 
}
