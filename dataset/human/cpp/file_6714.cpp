#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

double distpp(double x1, double y1, double x2, double y2){
    return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}

double distpl(double xp, double yp,
              double x1, double y1,
              double x2, double y2){
    return abs((y1-y2)*(xp-x1)-(x1-x2)*(yp-y1))
           /distpp(x1, y1, x2, y2);
}

int main(){
    int n, m, i, j;
    while( cin >> n, n ){
        vector<double> wx(n),wy(n),r(n);
        for(i=0;i<n;i++){
            cin>>wx[i]>>wy[i]>>r[i];
        }
        cin >> m;
        double tx, ty, sx, sy;
        for(i=0;i<m;i++){
            cin>>tx>>ty>>sx>>sy;
            bool safe = false;
            for(j=0;j<n;j++){
                double d1 = distpp(wx[j],wy[j],tx,ty),
                       d2 = distpp(wx[j],wy[j],sx,sy);
                if( (d1-r[j])*(d2-r[j]) < 0 ){
                    safe = true; break;
                }
                if( d1 < r[j] ) continue;
                if( distpl(wx[j],wy[j],tx,ty,sx,sy) <= r[j] &&
                    ((sx-tx)*(sx-wx[j])+(sy-ty)*(sy-wy[j]))*
                    ((sx-tx)*(tx-wx[j])+(sy-ty)*(ty-wy[j])) < 0 ){
                    safe = true; break;
                }
            }
            if( safe ){
                cout << "Safe" << endl;
            }else{
                cout << "Danger" << endl;
            }
        }
    }
    return 0;
}
