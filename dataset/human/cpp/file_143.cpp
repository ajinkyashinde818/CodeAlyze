#include <bits/stdc++.h>
using namespace std;

int main()
{
int r;
int g;
int b;
int n;
int pattern = 0;
cin >> r >> g >> b >> n;
for (int rbox = 0; rbox < n/r+1; rbox++){
  for (int gbox = 0; gbox < (n - r*rbox)/g+1; gbox++){
    if ((n - r*rbox - g*gbox)%b == 0) {
      pattern++;
    }
  }
}
cout << pattern << endl;
}
