#include <iostream>
#include <vector>
int main() {
int n, m;
std::cin >> n >> m;
std::vector<std::string> a(n);
std::vector<std::string> b(m);
for (int i = 0; i <n;i++) {
    std::cin >> a[i];
}
for (int i = 0; i <m;i++) {
    std::cin >> b[i];
}
bool flag;
for (int i = 0; i < n-m+1; i++) { //a's row; n-m+1 = 2
      int row = i;
      int col = 0;
      flag = false;
      for (int j = 0; j< m; ) { // b's row
               if (a[row].substr(col, m) == b[j]) {
                        row++;
                        j++;
                        flag = true;
               } else if (col < n-m) {
                      col++;
                      row = i; // reset
                      j = 0; // reset
                      flag = false;
              } else {
                     flag = false;
                      break;
              }
        }
    if (flag) {
             break;
}
}
 
if (flag) {
 std::cout << "Yes" << std::endl;
} else {
  std::cout << "No" << std::endl;
}
return 0;
}
