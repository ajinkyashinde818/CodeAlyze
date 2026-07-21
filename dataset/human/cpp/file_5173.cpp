/* 
 * Project: AtCoder Beginners Contest 170 A - Five Variables
 * Author: toms74209200 <https://github.com/toms74209200>
 *
 * Created on 2020/06/14
 * Copyright (c) 2020 toms74209200
 * 
 * This software is released under the MIT License.
 * http://opensource.org/licenses/mit-license.php
 */
#include <cstdio>
using namespace std;

int n;
int r;

void solve() {
    
    if (n > 10) {
        printf("%d\n", r);
        return;
    }
    printf("%d\n", r+100*(10-n));

}

int main() {

    scanf("%d", &n);
    scanf("%d", &r);

    solve();

}
